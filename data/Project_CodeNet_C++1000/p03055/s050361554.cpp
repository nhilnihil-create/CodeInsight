/* be name khoda */

// #define stream_enable
#define long_enable

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>

// #include <bits/stdc++.h>
// #include <numeric>
// #include <iomanip>
// #include <cmath>
// #include <bitset>
// #include <fstream>

using namespace std;

#ifdef stream_enable
#define cin sss
#endif

#ifdef long_enable
typedef long long int ll;
#else
typedef int ll;
#endif

typedef pair<ll, ll> pii;
typedef pair<pii, ll> ppi;
typedef pair<ll, pii> pip;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef vector<pii> vpii;

const ll MOD = 1000000007;

const long long BIG = 1446803456761533460LL;
const int Big = 336860180;

#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back

#define debug(x) cout << #x << " -> " << (x) << endl;
#define debug2(x, y) cout << #x << ' ' << #y << " -> " << (x) << ' ' << (y) << endl;
#define debug3(x, y, z) cout << #x << ' ' << #y << ' ' << #z << " -> " << (x) << ' ' << (y) << ' ' << (z) << endl;
#define debug4(x, y, z, t) cout << #x << ' ' << #y << ' ' << #z << ' ' << #t << " -> " << (x) << ' ' << (y) << ' ' << (z) << ' ' << (t) << endl;
#define debugp(x) cout << #x << " -> " << "(" << (x).ff << ", " << (x).ss << ")" << endl;
#define debuga(x, n) cout << #x << " -> "; fori (i1_da, n) { cout << (x)[i1_da] << ' '; } cout << endl
#define debugap(x, n) cout << #x << " ->\n"; fori (i1_dap, n) { cout << "(" << (x)[i1_dap].ff << ", " << (x)[i1_dap].ss << ")" << endl; } cout << endl
#define debugaa(x, n, m) cout << #x << " ->\n"; fori (i1_daa, n) { fori (i2_daa, m) { cout << (x)[i1_daa][i2_daa] << ' '; } cout << '\n'; } cout << endl
#define debugav(x, n) cout << #x << " ->\n"; fori (i1_dav, n) { fori (i2_dav, (x)[i1_da].size()) { cout << (x)[i1_dav][i2_dav] << ' '; } cout << '\n'; } cout << endl
#define debugia(x, n) cout << #x << " ->\n"; fori (i1_dia, n) { cout << i1_dia << " : " << (x)[i1_dia] << '\n'; } cout << endl

#define forifrom(i, s, n) for(ll i = (s); i < (n); ++i)
#define forirto(i, n, e) for(ll i = (n) - 1; i >= (e); --i)
#define fori(i, n) forifrom (i, 0, n)
#define forir(i, n) forirto (i, n, 0)

#define smin(a, b) a = min(a, (b))
#define smax(a, b) a = max(a, (b))

#define Add(a, b) a = (a + (b)) % MOD
#define Mul(a, b) a = (a * (b)) % MOD

stringstream sss;

// -----------------------------------------------------------------------

const ll maxn = 200010;

ll n;
vi g[maxn];
ll maxh[maxn];
ll diam = 0;

void dfs(ll x, ll par) {
    vi hs;
    for (auto y : g[x]) {
        if (y == par) continue;
        dfs(y, x);
        hs.pb(maxh[y] + 1);
        smax(maxh[x], maxh[y] + 1);
    }
    if (hs.size() >= 1) {
        auto it = max_element(all(hs));
        ll a = *it;
        hs.erase(it);
        smax(diam, a);
        if (hs.size() >= 1) {
            it = max_element(all(hs));
            ll b = *it;
            smax(diam, a + b);
        }
    }
}

void MAIN() {

    cin >> n;
    fori (i, n - 1) {
        ll a, b;
        cin >> a >> b;
        --a, --b;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(0, 0);

    cout << (diam % 3 == 1 ? "Second" : "First") << '\n';

}

// -----------------------------------------------------------------------

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cout << fixed << setprecision(10);
    sss << R"(
6
1 2
2 3
2 4
4 6
5 6
    )";
    MAIN();
    return 0;
}
