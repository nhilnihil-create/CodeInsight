#include <stdio.h>

int main() {

    int x,y,z;
    scanf("%d %d", &x, &y);

    if(y % x == 0) {
        z = x + y;
        printf("%d", z);
    } else {
        z = y - x;
        printf("%d", z);
    }

    return 0;
}