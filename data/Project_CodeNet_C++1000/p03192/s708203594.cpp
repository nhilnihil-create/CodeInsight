#include <cstdio>
 
int main()
{
    char N[10];
    scanf("%s", N);
 
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        if (N[i] == '2') ++ans;
    }
 
    printf("%d\n", ans);
    return 0;
}