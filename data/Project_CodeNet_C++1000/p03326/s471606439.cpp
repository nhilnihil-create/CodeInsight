#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second

void solve() {
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    vector<ll> X(n), Y(n), Z(n);
    rep(i, n) cin >> X[i] >> Y[i] >> Z[i];
    for(int x = 1; x >= -1; x -= 2) for(int y = 1; y >= -1; y -= 2) for(int z = 1; z >= -1; z -= 2){
        vector<ll> A(n);
        rep(i, n) {
            A[i] = X[i] * x + Y[i] * y + Z[i] * z;
        }
        sort(rall(A));
        ll ret = 0;
        rep(i, m) ret += A[i];
        ans = max(ans, ret);
    }
    cout << ans << endl;
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
