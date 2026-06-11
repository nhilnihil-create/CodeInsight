#include<bits/stdc++.h>
using namespace std;
#define d double
d dp[305][305][305];
int ar[305];
int mp[4];
int n;
d f(int a, int b, int c)
{
    if (!a && !b & !c)
        return 0;
    d &ans = dp[a][b][c];
    if (ans != -1) return ans;
    ans = n;
    if (a != 0)
        ans += a * f(a - 1, b, c);
    if (b != 0)
        ans += b * f(a + 1, b - 1, c);
    if (c != 0)
        ans += c * f(a, b + 1, c - 1);
    ans /= (a + b + c);
    return ans;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 305; ++i)
    {
        for (int j = 0; j < 305; ++j)
        {
            for (int k = 0; k < 305; ++k)
            {
                dp[i][j][k] = -1;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &ar[i]);
        mp[ar[i]]++;
    }
    cout << fixed << setprecision(10) << f(mp[1], mp[2], mp[3]);
    return 0;
}