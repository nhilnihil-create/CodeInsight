#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>

using namespace std;

#define int long long
typedef long double ld;
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vi>
#define viii vector<vii>
#define vpii vector<pii>
#define vb vector<bool>
#define vbb vector<vb>
#define vs vector<string>
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define in(a, x) for (int i = x; i < (a).size(); ++i) cin >> (a)[i]
#define out(a) for (auto qwe : a) cout << qwe << " "

const int INF = 1e9;
const int INF64 = 1e18;
const int MOD = 1e9 + 7;
const int MOD9 = 1e9 + 9;
const int MOD3 = 998244353;
const int P = 37;

const int mxn = 200000;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    vii dp(n + 1, vi(n + 1, 0));
    vii p(n + 1, vi(n + 1, 0));

    dp[1][1] = 1;
    for (int k = 1; k <= n; ++k) {
        p[1][k] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        bool less = s[i - 2] == '<';

        for (int j = 1; j <= i; ++j) {
            if (less) {
                dp[i][j] = p[i - 1][j - 1];
            } else {
                dp[i][j] = (p[i - 1][i - 1] - p[i - 1][j - 1] + MOD) % MOD;
            }

            p[i][j] = (p[i][j - 1] + dp[i][j]) % MOD;
        }
    }

    cout << p[n][n];
}