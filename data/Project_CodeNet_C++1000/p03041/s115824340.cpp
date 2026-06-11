#include <stdio.h>

int main()
{
    char s[52];
    int n;
    int k;
    
    scanf("%d %d\n%s", &n, &k, &s);
    s[n] = '\0';
    s[k - 1] = s[k - 1] + 32;
    
    printf("%s", s);

    return 0;
}