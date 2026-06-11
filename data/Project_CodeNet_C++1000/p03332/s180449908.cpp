#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <tuple>
#include <cstring>
#include <map>
#include <iomanip>
#include <ctime>
#include <complex>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _ << " " <<
#define all(X) (X).begin(), (X).end()
#define len(X) (X).size()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Tiii tuple<int, int, int>
#define Tlll tuple<ll, ll, ll>

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    ll r = a % b;
    while (r != 0) {
        a = b;  b = r;
        r = a % b;
    }
    return b;
}

ll pw(ll x, ll y, ll mod) {
    if (y == 0) return 1;
    else if (y == 1) return x % mod;
    else if (y % 2 == 0) {
        ll p = pw(x, y / 2, mod);
        return p * p % mod;
    }
    else {
        ll p = pw(x, y / 2, mod);
        return p * p % mod * x % mod;
    }
}

ll dv(ll x, ll y, ll mod) {
    x %= mod;
    y %= mod;
    return x * pw(y, mod - 2, mod) % mod;
}
 
ll comb(ll n, ll r, ll mod) {
    ll v = 1;
    if (n < r || n < 0 || r < 0) return 0;
    for (int i = 1; i <= r; i++) {
        v = v * dv(n - i + 1, i, mod) % mod;
    }
    return v;
}

int main() {
    ll n, a, b, k, mod = 998244353;
    cin >> n >> a >> b >> k;

    ll p = n + 1;
    for (int i = 0; i < b; i++) {
        if ((k - i*a) % b == 0) {
            p = i;
            break;
        }
    }
    ll q = (k - p*a) / b;
    ll l = a / gcd(a, b) * b;
    while (q < 0 || n < q) {
        p += l / a;
        q -= l / b;
    }
    if (p > n) {
        cout << 0 << endl;
        return 0;
    }
    
    ll ans = 0;
    ll ci = comb(n, p, mod), cj = comb(n, q, mod);
    for (ll i = p; i <= n; i += l / a) {
        ll j = (k - i*a) / b;
       // cout << i _ j << endl;
        if (0 <= j && j <= n) {
            ans += ci * cj;
            ans %= mod;
            for (int x = 1; x <= l / a; x++) {
                ci = ci * dv(n - i - x + 1, i + x, mod) % mod;
            }
            for (int x = 1; x <= l / b; x++) {
                cj = cj * dv(j - x + 1, n - j + x, mod) % mod;
            }
            //cout << ans _ ci _ cj << endl;
        }
    }
    cout << ans << endl;


}
