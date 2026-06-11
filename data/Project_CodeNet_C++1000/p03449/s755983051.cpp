#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma 03
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2")

#define ll long long
#define ld long double
#define fi first
#define se second
#define sz(x) x.size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define rep(i, x, n) for (ll i = x; i < n; i++)
#define fastio() ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0)
#define int long long

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;

inline void EXECUTE_TIME() {cout << endl << setprecision(10) << fixed << "CPU Time: " << clock() / double(CLOCKS_PER_SEC) << " sec(s)\n";}

template <class T> inline T RD(T &a) {T x; cin >> x; return a = x;}
template <class T> inline T gcd(T a, T b) {if (b) return gcd(b, a % b); else return a;}
template <class T> inline T lcm(T a, T b) {return a / gcd(a,b) * b;}
template<typename T> using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

//const int N = 3e5 + 7;
//
//namespace DCP {
//    struct PSU {int u, hu, v, hv;};
//    struct Que {
//        int u, v, United;
//        Que(int _u, int _v) : u(_u), v(_v), United(0) {}
//    };
//    int p[N], h[N];
//    int cnt;
//    stack<PSU> ops;
//
//    void init(int n) {
//        iota(p + 1, p + n + 1, 1);
//        cnt = n;
//    }
//
//    int lead(int i) {
//        for (; i != p[i]; i = p[i]);
//        return i;
//    }
//
//    bool join(int i, int j) {
//        i = lead(i);
//        j = lead(j);
//        if (i == j) return false;
//        if (h[i] < h[j]) swap(i, j);
//        ops.push({i, h[i], j, h[j]});
//        cnt--;
//        p[j] = i;
//        if (h[i] == h[j]) h[i]++;
//        return true;
//    }
//
//    void rollback() {
//        if (ops.empty()) return;
//        h[ops.top().u] = ops.top().hu;
//        p[ops.top().v] = ops.top().v;
//        cnt++;
//        ops.pop();
//    }
//
//    vector<Que> Q[N << 2];
//    vector<int> ans;
//
//    void add(int i, int l, int r, int L, int R, Que x) {
//        if (l > R || L > r) return;
//        if (L <= l && r <= R) {
//            Q[i].pb(x);
//            return;
//        }
//        int m = (l + r) / 2;
//        add(i << 1, l, m, L, R, x); m++;
//        add(i << 1 | 1, m, r, L, R, x);
//    }
//
//    void cal(int i, int l, int r) {
//        for (Que &t : Q[i])
//            t.United = join(t.u, t.v);
//        if (l == r) ans.pb(cnt);
//        else {
//            int m = (l + r) / 2;
//            cal(i << 1, l, m); m++;
//            cal(i << 1 | 1, m, r);
//        }
//
//        reverse(all(Q[i]));
//        for (Que &t : Q[i])
//            if (t.United)
//                rollback();
//    }
//}
//
//using DCP::add;
//using DCP::ans;
//
//bool ask[N];

const int N = 101;

int dp[2][N], a[2][N];

signed main() {
//    freopen("connect.in", "r", stdin);
//    freopen("connect.out", "w", stdout);
    fastio();

    int n; cin >> n;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            dp[i][j] = a[i][j];
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0) dp[i][j] = max(dp[i - 1][j] + a[i][j], dp[i][j]);
            if (j > 0) dp[i][j] = max(dp[i][j - 1] + a[i][j], dp[i][j]);
        }
    }

    cout << dp[1][n - 1];

//    EXECUTE_TIME();
}

