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

bool comp(pair<pii, int> a, pair<pii, int> b) {
    return a.ff.ff + a.ff.ss > b.ff.ff + b.ff.ss;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<pii, int>> p(n);

    for (int k = 0; k < n; ++k) {
        cin >> p[k].ff.ff >> p[k].ff.ss >> p[k].ss;
    }

    vii dp(n + 1, vi(1e4 + 1, -1));

    sort(all(p), comp);

    for (int i = 0; i < n; ++i) {
        int w = p[i].ff.ff;
        int s = p[i].ff.ss;
        int c = p[i].ss;

        dp[i + 1][s] = max(dp[i + 1][s], c);

        for (int j = 10000; j >= 0; --j) {
            if (dp[i][j] == -1) continue;

            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j >= w) {
                dp[i + 1][min(j - w, s)] = max(dp[i + 1][min(j - w, s)], dp[i][j] + c);
            }
        }
    }

    cout << *max_element(all(dp[n]));
}