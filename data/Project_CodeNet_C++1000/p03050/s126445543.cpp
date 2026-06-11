#include<bits/stdc++.h>
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define print(x) cout << (x) << endl;
#define printa(x, n) for(ll i = 0; i < n; i++) {cout << (x[i]) << " ";} cout << endl;
using namespace std;
using ll = long long;

int main(void) {
    ll n;
    cin >> n;

    ll ans = 0;

    for (ll i = 1LL; i * i <  n; i++) {
        if ((n - i) % i == 0) if (n % ((n - i) / i) != 0) ans += (n - i) / i;
    }
    
    cout << ans << endl;
    return 0;
}