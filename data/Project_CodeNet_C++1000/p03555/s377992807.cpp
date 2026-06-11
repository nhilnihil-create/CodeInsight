#include <cstdio>

char s[6];

int main()
{
    scanf("%s %s", &s[0], &s[3]);
    if (s[0] == s[5] && s[1] == s[4] && s[2] == s[3]) printf("YES\n");
    else printf("NO\n");

    return 0;
}