#include<cstdio>
#include<cstring>

const int MAXN = 100 + 10;
int a[MAXN][MAXN];

int main()
{
    int n, h, w;
    int ans = 0;
    scanf("%d %d %d", &n, &h, &w);
    if(n<h || n<w)
        printf("%d", ans);
    else 
    {
        ans = (n + 1 - h) * (n + 1 - w);
        printf("%d", ans);
    }
    return 0;
}