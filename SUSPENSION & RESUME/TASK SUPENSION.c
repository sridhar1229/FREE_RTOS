#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>

// Structure to hold task priority information
struct task {
    char priority[10];
};

// Initialize priority levels
struct task priority[] = { {"high"}, {"low"}, {"medium"} };

// Task functions
void high_priority_task(void *pvParameters) {
    struct task *ptr = (struct task *)pvParameters;
    while (1) {
        printf("%s Priority Task Running\n", ptr->priority);
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1 second
    }
}

void low_priority_task(void *pvParameters) {
    struct task *ptr = (struct task *)pvParameters;
    while (1) {
        printf("%s Priority Task Running\n", ptr->priority);
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1 second
    }
}

void medium_priority_task(void *pvParameters) {
    struct task *ptr = (struct task *)pvParameters;
    while (1) {
        printf("%s Priority Task Running\n", ptr->priority);
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1 second
    }
}

void app_main() {
    // Create tasks with different priorities
    xTaskCreate(high_priority_task, "HighPriorityTask", 2048, (void *)&priority[0], 3, NULL);
    xTaskCreate(medium_priority_task, "MediumPriorityTask", 2048, (void *)&priority[2], 2, NULL);
    xTaskCreate(low_priority_task, "LowPriorityTask", 2048, (void *)&priority[1], 1, NULL);

    // The app_main task will terminate here
}
