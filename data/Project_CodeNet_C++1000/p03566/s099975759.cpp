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
const double PI = atan(1.0) * 4.0;
// const int MOD = 998244353;
const ll LINF = 1e18 + 1;
const ll dx[] = {1, 0, -1, 0};
const ll dy[] = {0, 1, 0, -1};

ll N;
vector<double> t, v;

signed main() {
    cin >> N;
    REP(i, N) t.emplace_back(IN());
    REP(i, N) v.emplace_back(IN());
    double ans = 0, sp = 0;
    REP(i, N) {
        for(double j = 0; j < t[i]; j += 0.5) {
            bool keep = true, up = true;
            double rem = t[i] - j - 0.5;
            FOR(k, i + 1, N) {
                rem += t[k];
                if(sp + 0.5 - rem > v[k + 1]) up = false;
                if(sp - rem > v[k + 1]) keep = false;
            }
            if(sp + 0.5 <= v[i] && up && (sp + 0.5 - (t[i] - j - 0.5)) <= v[i + 1]) {
                ans += sp * 0.5;
                ans += 0.125;
                sp += 0.5;
            } else if(sp - v[i + 1] <= t[i] - j - 0.5 && keep) {
                ans += sp * 0.5;
            } else {
                ans += sp * 0.5;
                ans -= 0.125;
                sp -= 0.5;
            }
        }
    }
    printf("%.9f\n", ans);
}
