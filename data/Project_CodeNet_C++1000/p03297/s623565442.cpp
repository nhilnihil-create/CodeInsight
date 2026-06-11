#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORR(i, a, b) for(int i = (a); i > (b); --i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOREACH(x, a) for(auto &(x) : (a))
#define VECCIN(x)                                                              \
    for(auto &youso_ : (x)) cin >> youso_
#define mp make_pair
#define bitcnt __builtin_popcount
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

typedef long long ll;
typedef unsigned long long ul;
typedef vector<int> V;
typedef vector<ll> VL;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
typedef priority_queue<int> PQ;
typedef priority_queue<int, V, greater<int>> PQG;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

ll N, T;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin >> T;
    REP(loop, T) {
        LCIN(A, B, C, D);
        if(A < B || B > D) {
            cout << "No"
                 << "\n";
        } else {
            if(C >= B || C >= A) {
                cout << "Yes"
                     << "\n";
            } else {
                ll g = gcd(B, D);
                ll x = (A - C) / g;
                if((A - C) % g == 0) x--;
                if(x * g > A - B)
                    cout << "No"
                         << "\n";
                else
                    cout << "Yes"
                         << "\n";
            }
        }
    }
    return 0;
}
