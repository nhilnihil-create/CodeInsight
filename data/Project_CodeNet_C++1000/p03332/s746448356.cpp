#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <string.h>
#define rep(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
double PI = 3.1415926535897932;
const double EPS = 1e-9;
const ll MOD = 998244353;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

ll kai[300001];
ll mokai[300001];

ll mod_pow (ll x, ll y) {
    ll ret = 1;
    while (y) {
        if (y&1) ret = ret*x%MOD;
        x = x*x%MOD;
        y /= 2;
    }
    return ret;
}

void init (int _n) {
    kai[0] = 1;
    for (int i = 1; i <= _n; i++) kai[i] = kai[i-1]*i%MOD;
    for (int i = 0; i <= _n; i++) mokai[i] = mod_pow(kai[i],MOD-2);
}

ll conb (ll x, ll y) {
    ll z = x-y;
    ll ret = kai[x]*mokai[y]%MOD;
    ret = ret*mokai[z]%MOD;
    return ret;
}


ll n, a, b, k;

int main() {
    init(300000);
    cin >> n >> a >> b >> k;
    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        ll j = k-a*i;
        if (j < 0 || j%b != 0) continue;
        j /= b;
        if (j > n) continue;
        ans = (ans + conb(n, i) * conb(n, j)) % MOD;
    }
    cout << ans << endl;
}