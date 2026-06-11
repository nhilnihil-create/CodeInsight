#include <stdio.h>
int main(void){
    int n, a, b; scanf("%d%d%d", &n, &a, &b);
    bool flag = (b - a) & 1;
    puts(flag ? "Borys" : "Alice");
    return 0;
}