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
VL a;

// new
template <typename T> struct BIT {
    int n;
    vector<T> dat;

    BIT(ll n = 0) { initialize(n); }

    void initialize(ll nin) {
        n = nin + 1;
        dat.resize(n + 1);
        fill(All(dat), 0);
    }

    T sum(ll i) {
        T s = 0;
        while(i > 0) {
            s += dat[i];
            i = i & (i - 1);
        }
        return s;
    }

    T sum_between(ll i, ll j) {
        if(i > j) return 0;
        return sum(j) - sum(i - 1);
    }

    void plus(ll i, T x) {
        while(i <= n) {
            dat[i] += x;
            i += i & -i;
        }
    }

    ll lower_bound(T x) {
        ll ret = 0;
        ll k = 1;
        while(2 * k <= n) k <<= 1;
        for(; k > 0; k >>= 1) {
            if(ret + k <= n && dat[ret + k] < x) {
                x -= dat[ret + k];
                ret += k;
            }
        }
        return ret + 1;
    }
};

bool judge(ll x) {
    VL sum(N + 1, 0);
    ll all = (N + 1) * N / 2;
    ll S = 0;
    REP(i, N) { sum[i + 1] += sum[i] + (a[i] >= x ? 1 : -1); }
    FOREACH(s, sum) s += N + 1;
    auto num = BIT<ll>(2 * N + 1);
    num.plus(N + 1, 1);
    FOR(i, 1, N + 1) {
        S += num.sum(sum[i]);
        num.plus(sum[i], 1);
    }
    return S >= all - S;
}

signed main() {
    cin >> N;
    REP(i, N) a.emplace_back(IN());
    ll lb = 1, ub = LINF;
    while(ub - lb > 1) {
        ll mid = (ub + lb) / 2;
        if(judge(mid))
            lb = mid;
        else
            ub = mid;
    }
    cout << lb << "\n";
}
