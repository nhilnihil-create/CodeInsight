#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mx = 10000007;
const ll mod = 1e9 + 7;
const double pi = acos(-1);
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
#define FIO ios_base::sync_with_stdio(false);  cin.tie(NULL);


int main() {
    ll n, x;
    cin >> n;
    vector<ll>v(n+1);
    for (ll i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector<ll>f(n+1, 0), l(n+2, 0) ;
    l[n+1] = 0;
    for (ll i = 1; i <= n; i++) {
        f[i] = gcd(f[i-1], v[i]);
    }
    for (ll i = n ; i >= 1; i--) {
        l[i] = gcd(l[i+1], v[i]);
    }
    ll mn = 0;

    for (ll i = 1; i <= n ; i++) {
        mn = max (mn, gcd(f[i-1], l[i+1]));
    }
    cout << mn << endl;
}
