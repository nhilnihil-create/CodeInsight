#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

ll dp[202020];
ll sum[202020];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    c.erase(unique(ALL(c)), c.end());
    n = c.size();
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        (sum[c[i]] += dp[i]) %= MOD;
        (dp[i + 1] += sum[c[i]]) %= MOD;
    }
    cout << dp[n] << endl;
}