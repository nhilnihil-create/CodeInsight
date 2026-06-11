
#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;

#define rep(a,n) for(ll a = 0;a < n;a++)

static const ll INF = 1e18;
static const ll mod = 1e9+7;

template<typename T>
static inline void chmin(T& ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T& ref, const T value) {
    if (ref < value) ref = value;
}

ll mpow(ll x, ll n) {
    ll ans = 1; x %= mod;
    while (n != 0) {
        if (n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n = n >> 1;
    }
    return ans;
}

ll inv_mod(ll a) { return mpow(a, mod - 2); }

class Factorial {
public:
    ll cmb(ll a, ll b) {
        if (a == 0 && b == 0) return 1;
        if (a < b || a < 0 || b < 0) return 0;
        ll c = 1;
        for (int i = a,j=1; i > a - b; i--,j++) {
            c *= i;
            c /= j;
        }
        return c;
    }
};

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> colors(n, -1);
    std::function<bool(int, int)> dfs = [&](int current, int color) {
        if (colors[current] >= 0) {
            if (colors[current] != color) {
                return false;
            }
            return true;
        }
        colors[current] = color;
        for (auto p : graph[current]) {
            if (!dfs(p, (color + 1) % 2)) {
                return false;
            }
        }
        return true;
    };
    if (!dfs(0, 0)) {
        cout << n * (n - 1) / 2 - m << endl;
        return 0;
    }
    ll white = 0, black = 0;
    for (int i = 0; i < n; i++) {
        if (colors[i])white++;
        else black++;
    }
    cout << white * black - m << endl;
    return 0;
}
