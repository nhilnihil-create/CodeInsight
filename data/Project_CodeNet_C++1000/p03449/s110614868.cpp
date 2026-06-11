#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
inline int readInt();
int dp[3][105];
int a[3][105];
int main()
{
    int n;
    n = readInt();
    for (int i = 1; i <= 2; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            a[i][j] = readInt();
        }
    }
    for (int i = 1; i <= 2; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            a[i][j] = max(a[i][j] + a[i - 1][j], a[i][j] + a[i][j - 1]);
        }
    }
    cout << a[2][n] << endl;
    return 0;
}

inline int readInt()
{
    int s = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        s = (s << 1) + (s << 3) + (c ^ 48);
        c = getchar();
    }
    return f * s;
}