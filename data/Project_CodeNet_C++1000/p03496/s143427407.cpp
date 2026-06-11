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
#define bitcnt __builtin_popcount
#define SZ(x) ((ll)(x).size())
#define fi first
#define se second
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
template <typename T> using PQG = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using PQ = priority_queue<T>;

typedef long long ll;
typedef unsigned long long ul;
typedef vector<ll> VL;
typedef pair<ll, ll> PL;

const int INF = 1e9;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const ll LINF = 1e18 + 1;
const ll dx[] = {1, -1, 0, 0};
const ll dy[] = {0, 0, 1, -1};

ll N;
VL a;
vector<PL> ans;

signed main() {
    cin >> N;
    REP(i, N) a.emplace_back(IN());
    auto m = min_element(All(a)), M = max_element(All(a));
    if(*m > 0) {
        cout << N - 1 << "\n";
        REP(i, N - 1) { cout << i + 1 << " " << i + 2 << "\n"; }
        return 0;
    }
    if(*M <= 0) {
        cout << N - 1 << "\n";
        REPR(i, N - 2) { cout << i + 2 << " " << i + 1 << "\n"; }
        return 0;
    }
    auto pl = (abs(*m) > abs(*M) ? m : M);
    ll idx = pl - a.begin();
    cout << 2 * N - 2 << "\n";
    REP(i, N) {
        if(i != idx) {
            cout << idx + 1 << " " << i + 1 << "\n";
        }
    }
    if(pl == m) {
        REPR(i, N - 2) { cout << i + 2 << " " << i + 1 << "\n"; }
    } else {
        REP(i, N - 1) { cout << i + 1 << " " << i + 2 << "\n"; }
    }
}