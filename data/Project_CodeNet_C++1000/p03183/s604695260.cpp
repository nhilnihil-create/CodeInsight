#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //gp_hash_table

#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define sz(a) (int) a.size()
#define bitcount(a) __builtin_popcount(a)

using namespace std;
// using namespace __gnu_pbds;


typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const ll oo = 1e15;
const int N = (int) 1010;
const int M = 1e4 + 10;

struct item {
    int w, s, v;
    item(int w, int s, int v): w(w), s(s), v(v) {}
    bool operator<(const item& o) const {
        return s - o.w < o.s - w;
    }
};

void solve() {
    int n; cin >> n;
    vector<item> a;
    for(int i = 0; i < n; ++i) {
        int w, s, v; cin >> w >> s >> v;
        a.eb(w, s, v);
    }
    sort(all(a)); a.insert(a.begin(), item(-1, -1, -1));
    vector<vector<ll>> dp(n + 1, vector<ll>(2 * M, -oo));
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i) {
        for(int w = 0; w < 2 * M; ++w) {
            dp[i][w] = dp[i - 1][w];
        }
        for(int pw = 0; pw <= M && pw <= a[i].s; ++pw) {
            dp[i][pw + a[i].w] = max(dp[i][pw + a[i].w], dp[i - 1][pw] + a[i].v);
        }
    }
    cout << *max_element(all(dp[n])) << '\n';
}

int main() {
    // freopen("input.in", "r", stdin);
    // freopen("input.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
    cout << fixed;
    // int t; cin >> t; while(t--)
    solve();
    cout.flush();
    return 0;
}