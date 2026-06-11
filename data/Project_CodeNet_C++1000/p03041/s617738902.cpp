#include <stdio.h>

int main(){
    int a,b;
    scanf("%d %d\n", &a , &b);
    char name[a];
    scanf("%s", name);
    name[b-1] = name[b-1] + 32;
    printf("%s\n", name);
    return 0;
}