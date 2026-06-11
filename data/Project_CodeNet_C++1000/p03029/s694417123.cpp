#include <stdio.h>
int main(){
    int a, piece;
    scanf("%d %d", &a, &piece);
    piece = piece + a*3;
    int pie = piece / 2;
    printf("%d\n", pie);
    return 0;
}