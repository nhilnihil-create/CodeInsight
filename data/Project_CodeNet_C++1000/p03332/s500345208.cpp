#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
// constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

constexpr int MOD = 998244353;

long long inv(long long n) {
    long long res = 1;
    while (n > 1) {
        res *= (MOD - MOD/n);
        res %= MOD;
        n = MOD % n;
    }
    return res;
}

void solve() {
    ll n, a, b, k;
    cin >> n >> a >> b >> k;

    vector<ll> comb(n+1);
    ll nume = 1, deno = 1;
    for (int i=0; i<n+1; ++i) {
        comb.at(i) = nume * inv(deno) % MOD;
        nume *= n - i;
        deno *= i + 1;
        nume %= MOD;
        deno %= MOD;
    }

    ll res = 0;
    for (ll i=0; i<=n; ++i) {
        if (a * i > k) break;
        if ((k - a * i) % b == 0) {
            ll j = (k - a * i) / b;
            if (j > n) continue;
            res += comb.at(i) * comb.at(j);
            res %= MOD;
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
