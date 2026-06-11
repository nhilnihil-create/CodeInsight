#include <stdio.h>

int main(){
    int a, p;
    scanf("%d %d", &a, &p);
    a *= 3;
    a += p;
    a/=2;
    printf("%d\n", a);
    
    return 0;
}
