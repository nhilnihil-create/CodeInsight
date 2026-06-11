#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for (int i = 0; i < j; i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n,k;
    cin>>n>>k;
    vll a(n), b(n);
    rep(i, n) cin>>a[i];
    rep(i, n) if (i == 0) {
        b[0] = a[0];
    } else {
        b[i] = b[i - 1] + a[i];
    }

    vll v(n * (n + 1) / 2);
    int idx = 0;
    rep(i, n) for (int j = i + 1; j <= n; j++) {
        ll s = b[j - 1] - (i - 1 >= 0 ? b[i - 1] : 0);
        // cout << idx << " " << s << endl;
        v[idx++] = s;
    }

    for (int i = 60; i >= 0; i--) {
        vll vv;
        rep(j, v.size()) {
            if ((1LL << i) & v[j]) vv.push_back(v[j]);
        }
        // cout << i << " "  << " " << vv.size() << endl;
        if (vv.size() >= k) {
            v.swap(vv);
            if (v.size() == k) break;
        }
    }
    
    ll ans = v.size() > 0 ? v[0] : 0;
    rep(i, v.size()) {
        ans &= v[i];
        // cout << v[i] << endl;
    }

    cout << ans << endl;

    return 0;
}
