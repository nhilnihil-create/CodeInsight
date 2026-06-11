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

ll N;
VL a;
vector<PL> st;

void normalize() {
    ll sz = st.size();
    if(sz > 1) {
        if(st[sz - 1].first == st[sz - 2].first) {
            st[sz - 2].second += st[sz - 1].second;
            st.pop_back();
        }
    }
}

void increment() {
    if(st.back().second == 1) {
        st.back().first++;
    } else {
        st.back().second--;
        st.emplace_back(st.back().first + 1, 1);
    }
    normalize();
}

signed main() {
    cin >> N;
    REP(i, N) a.emplace_back(IN());
    ll lb = 0, ub = N + 1;
    while(ub - lb > 1) {
        ll mid = (ub + lb) / 2;
        bool judge = true;
        st.emplace_back(0, a[0]);
        FOR(i, 1, N) {
            if(a[i - 1] < a[i]) {
                st.emplace_back(0, a[i] - a[i - 1]);
            } else {
                ll rem = a[i - 1] - a[i];
                while(!st.empty() && st.back().second <= rem) {
                    rem -= st.back().second;
                    st.pop_back();
                }
                st.back().second -= rem;
                if(st.back().first == mid - 1) {
                    if(st.size() == 1) {
                        judge = false;
                        break;
                    }
                    ll tmp = st.back().second;
                    st.pop_back();
                    increment();
                    st.emplace_back(0, tmp);
                } else
                    increment();
            }
            normalize();
        }
        if(judge)
            ub = mid;
        else
            lb = mid;
        st.clear();
    }
    cout << ub << "\n";
    return 0;
}