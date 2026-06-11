#include <bits/stdc++.h>
#define int long long
#define rng(i, l, r) for (size_t i = (l); i < (r); ++i)
#define rep(i, n) rng(i, 0, n)
#define gnr(i, l, r) for (size_t i = (r)-1; i >= (l); i--)
#define per(i, b) gnr(i, 0, b)
#define ALL(obj) (obj).begin(), (obj).end()    //1,2,3,...
#define rALL(obj) (obj).rbegin(), (obj).rend() //...,3,2,1
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
using namespace std;
const int INF = 1e18;

void solve()
{

    // remove the bottom 3 lines when you submit this code.
    std::ifstream in("sample.txt");
    std::cin.rdbuf(in.rdbuf());

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> coins;
    coins.push_back(1);
    rng(i, 1, 7) coins.push_back(pow(6, i));
    rng(i, 1, 6) coins.push_back(pow(9, i));

    sort(ALL(coins));

    vector<vector<int>> dp(coins.size() + 1);
    rep(i, coins.size() + 1) dp[i].resize(100010);
    rep(i, 100010) dp[0][i] = INF;
    rep(i, coins.size() + 1) dp[i][0] = 0;

    for (int ic = 1; ic <= coins.size(); ic++)
    {
        for (int jv = 0; jv < 100010; jv++)
        {
            if (jv - coins[ic - 1] >= 0)
            {

                dp[ic][jv] = min(dp[ic - 1][jv], dp[ic][jv - coins[ic - 1]] + 1);
            }
            else
            {
                dp[ic][jv] = dp[ic - 1][jv];
            }
        }
    }

    cout << dp[coins.size()][n] << endl;
}

signed main()
{
    solve();
    return 0;
}
