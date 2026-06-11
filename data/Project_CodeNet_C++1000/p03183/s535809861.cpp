#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define int long long

typedef pair<int, int> ii;

const int mod = 1e9 + 7;

const int N = 1005;

const int M = 2e4 + 5;

const int inf = 1e15;

int n, dp[N][M], s[N], w[N], v[N];

vector<pair<ii, ii>> vec;

signed main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        vec.pb({{y + x, x}, {y, z}});
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++) {
        s[i + 1] = vec[i].se.fi;
        w[i + 1] = vec[i].fi.se;
        v[i + 1] = vec[i].se.se;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= M - 5; j++)
            dp[i][j] = -inf;
    }
    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= M - 5; j++) {
            if(j <= s[i + 1])
                dp[i + 1][j + w[i + 1]] = max(dp[i + 1][j + w[i + 1]], dp[i][j] + v[i + 1]);
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }
    int mx = 0;
    for(int j = 0; j <= M - 5; j++)
        mx = max(mx, dp[n][j]);
    cout << mx;
}
