#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 998244353
using namespace std;
ll fn(ll n, ll p) { return n - n % p; }
int main() {
    ll k;
    cin >> k;
    vector<ll> a(k);
    for(int i = 0; i < k; i++) {
        cin >> a[i];
    }
    ll ans1, ans2;
    ll l = 0, r = LLONG_MAX / 2;
    while(l + 1 < r) {
        ll m = (l + r) / 2;
        ll mc = m;
        for(int i = 0; i < k; i++) {
            mc = fn(mc, a[i]);
        }
        if(mc <= 2) {
            l = m;
        } else {
            r = m;
        }
    }
    ans1 = l;
    l = 0, r = LLONG_MAX / 2;
    while(l + 1 < r) {
        ll m = (l + r) / 2;
        ll mc = m;
        for(int i = 0; i < k; i++) {
            mc = fn(mc, a[i]);
        }
        if(mc >= 2) {
            r = m;
        } else {
            l = m;
        }
    }
    ans2 = r;
    if(ans1 >= ans2) {
        cout << ans2 << " " << ans1 << endl;
    } else {
        cout << -1 << endl;
    }
}