#include <stdio.h>

int main(){
    int apple, pieces;
    int answer;

    scanf("%d %d", &apple, &pieces);
    answer = ((apple*3) + pieces) / 2;
    printf("%d\n", answer);
    return 0;
}