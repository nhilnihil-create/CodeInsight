#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll ans = 1ll << 60;
    rep(i, n) {
        vector<ll> vec, tmp;
        rep(j, n) {
            if (a[j] < a[i]) {
                if (tmp.size() >= k) {
                    sort(tmp.begin(), tmp.end());
                    rep(t, tmp.size() - (k - 1)) {
                        vec.push_back(tmp[t]);
                    }
                }
                tmp.clear();
            } else {
                tmp.push_back(a[j]);
            }
        }
        if (tmp.size() >= k) {
            sort(tmp.begin(), tmp.end());
            rep(t, tmp.size() - (k - 1)) {
                vec.push_back(tmp[t]);
            }
        }
        sort(vec.begin(), vec.end());
        if (vec.size() >= q) {
            ans = min(ans, vec[q - 1] - vec[0]);
        }
    }
    cout << ans << endl;
}