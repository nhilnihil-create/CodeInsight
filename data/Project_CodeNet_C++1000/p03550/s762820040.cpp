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

const int N = 2005;
int n, z, w, ans;
int a[N];
int dp[N][2];

int solve(int x, int k) {
    if (dp[x][k] != -1) return dp[x][k];
    int ret = abs(a[x] - a[n]);
    if (k == 0) {
        for (int i = x + 1; i < n; ++i)
            ret = max(ret, solve(i, 1 - k));
    } else {
        for (int i = x + 1; i < n; ++i)
            ret = min(ret, solve(i, 1 - k));
    }
    return dp[x][k] = ret;
}
int main() {
    memset(dp, 255, sizeof dp);
    cin >> n >> z >> w;
    a[0] = w;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cout << solve(0, 0) << endl;
    return 0;
}
