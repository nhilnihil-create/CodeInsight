#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    
    ll n, k; cin >> n >> k;
    const ll p = 200001;
    vector<ll> num(p, 0);
    for (int i = 0; i < n; i++) {
        ll a; cin >> a;
        num[a]++;
    }
    sort(num.rbegin(), num.rend());
    ll ans = 0;
    for (int i = k; i < p; i++) {
        ans += num[i];
    }
    cout << ans << endl;
    return 0;
}