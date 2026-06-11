#include <bits/stdc++.h>

using namespace std;
using ll = long long;

////cout << std::fixed << std::setprecision(15) << y << endl;

int main() {
    ll n = 0;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);
    for(int i = 0;i < n;i++)cin >> a[i];
    for(int i = 0;i < n;i++)cin >> b[i];
    for(int i = 0;i < n;i++)cin >> c[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    ll sum = 0;
    for(ll i = 0;i < n;i++){
        auto ai = lower_bound(a.begin(),a.end(),b[i]);
        ll aa = ai - a.begin();
        auto ci = upper_bound(c.begin(),c.end(),b[i]);
        ll ca = c.end() - ci;
        sum += aa * ca;
    }
    cout << sum << endl;
    return 0;
}