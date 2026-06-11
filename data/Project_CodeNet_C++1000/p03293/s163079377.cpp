#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

bool solve(char *S, char *T)
{
    int n = strlen(S);
    for (int i = 0; i <= n; ++i)
    {
        char c = S[0];
        for (int i = 0; i < n; ++i)
        {
            S[i - 1] = S[i];
        }
        S[n - 1] = c;
        if (strcmp(S, T) == 0)
            return 1;
        else
        {
            continue;
        }
    }
    return 0;
}

int main()
{
    char S[105], T[105];
    scanf("%s", S);
    getchar();
    scanf("%s", T);
    if (solve(S, T))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}
