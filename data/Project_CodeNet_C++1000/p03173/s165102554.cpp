#include <bits/stdc++.h>

using namespace std;

int n;
int slimes[401];
long long memo[401][401] = {};

long long dp(int a, int b)
{
    if (a == b)
        return 0;
    if (memo[a][b] > 0)
        return memo[a][b];
    long long res = LLONG_MAX;
    long long sum = 0;
    for (int i = a; i < b; i++)
    {
        sum += slimes[i];
        res = min(res, dp(a, i) + dp(i + 1, b));
    }
    sum += slimes[b];
    res += sum;
    memo[a][b] = res;
    return res;
}

int main(void)
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d", &n);
    int ipt;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &slimes[i]);
    }
    long long res;
    res = dp(0, n - 1);
    cout << res << endl;
}