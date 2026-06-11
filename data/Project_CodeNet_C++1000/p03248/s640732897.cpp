/// IN THE NAME OF METAL
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define sz(x)                       (ll) x.size()
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second

ll Pow(ll a, ll b, ll md, ll ans = 1) {
    for (; b; b >>= 1, a = a * a % md)
        if (b & 1)
            ans = ans * a % md;
    return ans % md;
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7;
ll n;
string C;
vector<pll> E;

int main() {
    cin >> C;
    n = sz(C);
    C = '#' + C;
    if (C[1] != '1' || C[n] != '0') return !printf("-1\n");
    for (ll i = 1; i <= n - 1; i++) {
        if (C[i] != C[n - i]) return !printf("-1\n");
    } 
    for (ll i = 1; i <= n - 2; i++) {
        ll ind = i + 1;
        while (C[ind] != '1' && ind < n) ind++;
        for (ll j = i + 1; j < ind; j++) E.push_back({j, ind});
        E.push_back({i, ind});
        i = ind - 1;
    }
    E.push_back({n - 1, n});
    for (auto i : E) cout << i.F << ' ' << i.S << endl;
    return 0;
}

