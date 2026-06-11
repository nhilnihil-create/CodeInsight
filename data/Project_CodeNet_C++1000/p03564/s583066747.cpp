#include<stdio.h>

int main()
{
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    
    int i, total = 1;

    for (i = 0; i < n; i++) {
        if (total < k) {
            total = total * 2;
        } else {
            total = total + k;
        }
    }
    
    printf("%d\n", total);
    
    return 0;
}