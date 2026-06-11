#include<cstdio>
#include<cstring>
#include<cctype>

const int MAXN = 50 + 10;
char s[MAXN];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    getchar();
    fgets(s, n + 1, stdin);
    s[k - 1] = tolower(s[k - 1]);
    puts(s);
    return 0;
}