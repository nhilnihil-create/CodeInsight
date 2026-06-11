#define DEBUG
// #define FASTIO

#include <cassert>
#include <utility>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <bitset>
#include <chrono>
#include <cstdlib>
#include <functional>
#include <tuple>
#include <climits>
#include <limits>
#include <deque>
#include <list>
#include <array>
#include <stack>
#include <queue>
#include <random>
#include <complex>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

#define F first
#define S second 
#define pb push_back

#define endl "\n";
#ifdef FASTIO

#define pr(x) printf("%d", x)
#define ps    printf(" ")
#define pl(x) printf("%lld", x)
#define pf(x) printf("%lf", x)
#define sc(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define sf(x) scanf("%lf", &x)
#define IOS 

#endif

#ifndef FASTIO
    #define IOS { ios :: sync_with_stdio(false); cin.tie(0); }
#endif

#ifdef DEBUG
    #define dbg(s) {s;}
#endif

#ifndef DEBUG
    #define dbg(s)
#endif

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int grand(int x) {
    return uniform_int_distribution<int>(0, x - 1)(rng);
}

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef vector < int > vi;

const int maxn = 2e5 + 7;

const ll inf = 1e15;

const ll md = 1e9 + 7;


ll gcd(ll x, ll y) {
    if (x < y) return gcd(y, x);
    if (y == 0) return x;
    return gcd(y, x % y);
}

ll a[maxn];
ll sz[maxn];
pair<ll, int> q[maxn];
map<ll, int> M;
vector < int > G[maxn];

ll tsz[maxn];
ll f[maxn];

void dfs(int x, int pi) {
    sz[x] = 1; f[x] = 0;
    for (int y : G[x]) {
        if (y == pi) continue;
        dfs(y, x);
        sz[x] += sz[y];
        f[x] += f[y] + sz[y];
    }
}

int main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    IOS;

    int n; cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        q[i] = {a[i], i};
        sz[i] = 1;
        M[a[i]] = i;
    }

    sort(q + 1, q + n + 1);

    int eg = 0;
    vector < pii > veg;

    
    for (int i = n; i >= 1; i--) {
        int j = q[i].S;
        ll curz = n - sz[j] - sz[j];
        if (a[j] - curz < a[j]) {
            int y = M[a[j] - curz];
            if (y) {
                G[y].pb(j); G[j].pb(y);
                veg.pb({y, j});
                sz[y] += sz[j];
                eg++;
            }
        }
    }

    if (eg < n - 1) {
        cout << -1 << endl; return 0;
    }

    dfs(1, -1);

    if (f[1] != a[1]) {
        cout << -1 << endl;
        return 0;
    }

    for (pii e : veg) {
        cout << e.F << " " << e.S << endl;
    }
}
