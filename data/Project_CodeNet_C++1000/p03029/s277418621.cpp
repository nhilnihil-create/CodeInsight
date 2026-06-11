#include <stdio.h>

int main(){
    int a, p;

    scanf("%d %d", &a, &p);
    p = p + (a * 3);
    int applePie = p / 2;
    printf("%d\n", applePie);
    return 0;
    
}