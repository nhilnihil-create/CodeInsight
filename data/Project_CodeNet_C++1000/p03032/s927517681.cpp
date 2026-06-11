#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll INF = 1001001001001;
ll tb[50][50][100];

vector<ll> v;
ll ans = -INF;

ll dfs(int l, int r, int K) {
    if (l > r || K <= 0) return 0;
    if (l == r) return v[l] <= 0 ? 0 : v[l];
    if (tb[l][r][K] != -INF) return tb[l][r][K];
    ll a, b, c, d;
    // 取り出したものを最終的に使う
    a = dfs(l+1, r, K-1);
    b = dfs(l, r-1, K-1);

    // 取り出したものを最後に戻す
    c = dfs(l+1, r, K-2);
    d = dfs(l, r-1, K-2);

    return tb[l][r][K] = max(v[l] + a, max(v[r] + b, max(c, d)));
}

void solve() {
    int N, K;
    cin >> N >> K;
    v.resize(N);
    rep(i,N) cin >> v[i];

    rep(i,50) rep(j,50) rep(k,100) tb[i][j][k] = -INF;
    cout << dfs(0,N-1,K) << endl;
}

int main() {
    solve();
    return 0;
}
