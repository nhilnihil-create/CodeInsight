#include <stdio.h>

int main() {
    int ops, kval;
    int sum = 1;
    scanf("%d", &ops);
    scanf("%d", &kval);
    for (int i = 0; i < ops; i++) {
        if (sum < kval) {
            sum *= 2;
        } else {
            sum += kval;
        }
    }
    printf("%d", sum);
}