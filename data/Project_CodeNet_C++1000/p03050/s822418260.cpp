#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    ll ans = 0;
    for (ll r = 1; r * r <= N; r++) {
        ll m = (N - r) / r;
        if ((N - r) % r == 0 && m > r) ans += m;
    }

    cout << ans << endl;
}