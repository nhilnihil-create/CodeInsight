#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    ll ans = 1000000000;
    bool ok = true;
    rep(i, N) {
        ll cnt = 0;
        while (A[i] > 0) {
            if (A[i] % 2 == 0) {
                ++cnt;
                A[i] /= 2;
            } else break;
        }
        ans = min(ans, cnt);
    }
    if (ok) cout << ans << endl;
    else cout << 0 << endl;
}