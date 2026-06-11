#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;

ll a[16][16];
ll p[1 << 16];
ll dp[1 << 16];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    for (int i = 0; i < (1 << n); ++i)
    {
        vi b;
        for (int j = i; j; j -= (j&-j))
            b.push_back(__builtin_ctz(j));

        for (int j = 0; j < b.size(); ++j)
            for (int k = j + 1; k < b.size(); ++k)
                p[i] += a[b[j]][b[k]];
    }

    for (int i = 0; i < (1 << n); ++i)
        for (int s = i; s; s = (s-1)&i)
            dp[i] = max(dp[i], p[s] + dp[i^s]);
    
    cout << dp[(1 << n) - 1];
}
