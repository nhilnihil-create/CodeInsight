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
vector<vector<ll>> place(202020);

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
        place[c[i]].push_back(i);
    }
    dp[0] = 1;
    for (ll i = 0; i < n; i++)
    {
        (dp[i + 1] += dp[i]) %= MOD;
        ll color = c[i];
        ll itr = lower_bound(ALL(place[color]), i) - place[color].begin();
        if (itr > 0)
        {
            ll j = place[color][itr - 1];
            if (i - j > 1)
            {
                (dp[i + 1] += dp[j + 1]) %= MOD;
            }
        }
    }
    cout << dp[n] << endl;
}