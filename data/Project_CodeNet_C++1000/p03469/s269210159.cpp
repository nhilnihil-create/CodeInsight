#include <stdio.h>

int main(){
    int d, m, y;
    scanf("%d/%d/%d", &y, &m, &d);
    printf("2018/%.2d/%.2d\n", m, d);
    return 0;
}
