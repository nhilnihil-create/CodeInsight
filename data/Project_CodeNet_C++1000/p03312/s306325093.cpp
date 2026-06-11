#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

template <typename T> inline bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> inline bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<ll> a(n + 1);
    FOR(i, 1, n + 1) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    ll ans = 1e9;
    FOR(i, 2, n) {
        auto itr1 = lower_bound(a.begin(), a.end(), a[i] / 2),
             itr2 = lower_bound(a.begin(), a.end(), (a[i] + a[n]) / 2);

        if(abs(a[i] - 2 * *itr1) > abs(a[i] - 2 * *(itr1 - 1))) itr1--;
        if(abs(a[n] + a[i] - 2 * *itr2) > abs(a[n] + a[i] - 2 * *(itr2 - 1)))
            itr2--;
        ll mn = min(min(*itr1, a[i] - *itr1), min(*itr2 - a[i], a[n] - *itr2)),
           mx = max(max(*itr1, a[i] - *itr1), max(*itr2 - a[i], a[n] - *itr2));
        chmin(ans, mx - mn);
    }
    cout << ans << endl;
}