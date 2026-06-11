#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void warshall_floyd(long long n,vector<vector<long long>>& d) {
    for (long long k = 0; k < n; k++) {          // 経由する頂点
        for (long long i = 0; i < n; i++) {      // 始点
            for (long long j = 0; j < n; j++) {  // 終点
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
int main() {
    ll h, w;
    cin >> h >> w;
    vector<vector<ll>> c(10);
    for (ll i = 0; i < 10; i++) {
        for (ll j = 0; j < 10; j++) {
            ll t;
            cin >> t;
            c[i].push_back(t);
        }
    }
    warshall_floyd(10, c);

    vector<vector<ll>> a(h);
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w;j++){
            ll s;
            cin >> s;
            a[i].push_back(s);
        }
    }
    ll ans = 0;
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w;j++){
            if (a[i][j] != -1) ans += c[a[i][j]][1];
        }
    }
    cout << ans << endl;
}
