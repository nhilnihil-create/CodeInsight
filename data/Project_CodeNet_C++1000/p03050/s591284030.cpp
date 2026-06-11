#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<ll> fac;

void fact(ll n) {
    for (ll x = 1; x * x <= n; x++) {
        if (n % x == 0) {
            fac.push_back(x);

            if (n / x != x)
                fac.push_back(n/x);
        }
    }
    sort(fac.begin(), fac.end(), greater<ll>());
}

int main() {
    ll n, ans = 0;   cin >> n;
    fact(n);

    for (int i = 0; i < n; i++) {
        ll m = fac[i] - 1;
        if (m == 0)
            continue;
        if (n / m == n % m)
            ans += m;
        else 
            break;
    }
    
    cout << ans << endl;
    return 0;
}