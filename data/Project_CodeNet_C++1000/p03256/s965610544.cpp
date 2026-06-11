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

ll N, M;
string s;
vector<VL> G;
vector<map<char, ll>> cnt;

signed main() {
    cin >> N >> M >> s;
    G.resize(N);
    REP(i, M) {
        LCIN(a, b);
        G[--a].emplace_back(--b);
        if(a != b) G[b].emplace_back(a);
    }
    REP(i, N) sort(All(G[i]));
    set<ll> bad;
    cnt.resize(N);
    REP(i, N) {
        FOREACH(to, G[i]) { cnt[i][s[to]]++; }
        if(cnt[i]['A'] == 0 || cnt[i]['B'] == 0) bad.insert(i);
    }
    ll rem = N;
    while(!bad.empty()) {
        ll now = *bad.begin();
        bad.erase(bad.begin());
        rem--;
        FOREACH(to, G[now]) {
            if(to != now) {
                G[to].erase(lower_bound(All(G[to]), now));
                cnt[to][s[now]]--;
                if(cnt[to]['A'] == 0 || cnt[to]['B'] == 0) bad.insert(to);
            }
        }
    }
    Yes(rem);
}