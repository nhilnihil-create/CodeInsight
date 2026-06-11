//thuanqvbn03
#include <bits/stdc++.h>

using namespace std;

const int MaxN = 200005;

struct FenwickTree
{
    int n;
    vector<long long> FT;
    void init(int _n)
    {
        n = _n;
        FT.assign(n + 1, 0);
    }
    void Update(int x, long long val)
    {
        while (x <= n)
        {
            FT[x] = max(FT[x], val);
            x += (x & -x);
        }
    }
    long long Get(int x)
    {
        long long Resuft = 0;
        while (x > 0)
        {
            Resuft = max(Resuft, FT[x]);
            x -= (x & -x);
        }
        return Resuft;
    }
};

int n;
int h[MaxN], a[MaxN];
long long dp[MaxN];
FenwickTree FT;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    FT.init(n);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = FT.Get(h[i]) + a[i];
        FT.Update(h[i], dp[i]);
    }
    cout << FT.Get(n);
    return 0;
}