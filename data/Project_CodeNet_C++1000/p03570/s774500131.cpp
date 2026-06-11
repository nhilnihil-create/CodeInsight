#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

vector<int> dp(1 << 26, INF);

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.length();
    ll mask = 0;
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int b = s[i] - 'a';
        mask ^= (1LL << b);
        for (int j = 0; j < 26; j++)
        {
            dp[mask] = min(dp[mask], dp[mask ^ (1LL << j)] + 1);
        }
    }
    cout << max(1, dp[mask]) << endl;
}
