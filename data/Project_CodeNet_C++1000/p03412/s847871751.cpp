#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n),b(n);
    for (int i = 0;i < n;++i) cin >> a[i];
    for (int i = 0;i < n;++i) cin >> b[i];

    ll ans = 0;
    for (int i = 30;i >= 0;--i) {
        ll T = 1 << i;
        for (int j = 0;j < n;++j) b[j] %= T << 1;
        for (int j = 0;j < n;++j) a[j] %= T << 1;
        sort(b.begin(),b.end());
        ll cnt = 0;
        for (int j = 0;j < n;++j) {
            cnt += lower_bound(b.begin(),b.end(),2*T-a[j])-lower_bound(b.begin(),b.end(),T-a[j]);
            cnt += lower_bound(b.begin(),b.end(),4*T-a[j])-lower_bound(b.begin(),b.end(),3*T-a[j]);
        }
        if (cnt%2) ans ^= T;
    }
    cout << ans << endl;

    return 0;
}