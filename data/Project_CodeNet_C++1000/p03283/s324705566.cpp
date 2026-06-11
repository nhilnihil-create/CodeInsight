#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 505;
int n, m, q, l, r;
int dp[N][N];
int cnt[N][N];

int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        ++cnt[l][r];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j >= 1; --j) {
            dp[j][i] = cnt[j][i] + dp[j + 1][i] + dp[j][i - 1] - dp[j + 1][i - 1];
        }
    }
    for (int i = 0; i < q; ++i) {
        cin >> l >> r;
        cout << dp[l][r] << endl;
    }
    return 0;
}
