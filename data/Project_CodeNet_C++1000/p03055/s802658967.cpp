#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define FORR(i, a, b) for(ll i = (a); i > (b); --i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOREACH(x, a) for(auto &(x) : (a))
#define VECCIN(x)                                                              \
    for(auto &youso_ : (x)) cin >> youso_
#define mp make_pair
#define bitcnt __builtin_popcount
#define SZ(x) ((ll)(x).size())
#define All(a) (a).begin(), (a).end()
template <typename T = long long> inline T IN() {
    T x;
    cin >> x;
    return (x);
}
inline void CIN() {}
template <class Head, class... Tail>
inline void CIN(Head &&head, Tail &&... tail) {
    cin >> head;
    CIN(move(tail)...);
}
#define CINT(...)                                                              \
    int __VA_ARGS__;                                                           \
    CIN(__VA_ARGS__)
#define LCIN(...)                                                              \
    ll __VA_ARGS__;                                                            \
    CIN(__VA_ARGS__)
#define SCIN(...)                                                              \
    string __VA_ARGS__;                                                        \
    CIN(__VA_ARGS__)
#define Yes(a) cout << (a ? "Yes" : "No") << "\n"
#define YES(a) cout << (a ? "YES" : "NO") << "\n"
#define Printv(v)                                                              \
    {                                                                          \
        FOREACH(x, v) { cout << x << " "; }                                    \
        cout << "\n";                                                          \
    }
template <typename T = string> inline void eputs(T s) {
    cout << s << "\n";
    exit(0);
}
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
    std::fill((T *)array, (T *)(array + N), val);
}

typedef long long ll;
typedef unsigned long long ul;
typedef vector<ll> VL;
typedef pair<ll, ll> PL;
typedef priority_queue<ll> PQ;
typedef priority_queue<ll, VL, greater<ll>> PQG;

const int INF = 1e9;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const ll LINF = 1e18 + 1;
const ll dx[] = {1, -1, 0, 0};
const ll dy[] = {0, 0, 1, -1};

ll N;
vector<VL> G;
VL d;
vector<bool> used;

void dfs(ll now, ll dist) {
    d[now] = dist;
    FOREACH(to, G[now]) {
        if(!used[to]) {
            used[to] = true;
            dfs(to, dist + 1);
            used[to] = false;
        }
    }
}
signed main() {
    cin >> N;
    G.resize(N);
    d.resize(N);
    REP(i, N - 1) {
        LCIN(a, b);
        G[--a].emplace_back(--b);
        G[b].emplace_back(a);
    }
    ll root = 0;
    REP(loop, 2) {
        used.assign(N, false);
        used[root] = true;
        dfs(root, 0);
        root = max_element(All(d)) - d.begin();
    }
    ll dia = d[root];
    cout << (dia % 3 == 1 ? "Second" : "First") << "\n";
}