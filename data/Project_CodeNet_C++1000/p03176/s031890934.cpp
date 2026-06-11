#pragma GCC target("avx2")
#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std; typedef long double ld; typedef long long ll;
typedef unsigned long long ull;
#define endl "\n"
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define ALL(x) (x).begin(), (x).end()
constexpr int INF=1<<30; constexpr ll LINF=1LL<<60; constexpr ll mod=1e9+7; constexpr int NIL = -1;
template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
template<class T>inline int popcount(T a) {return __builtin_popcount(a);}
//-------------------
constexpr int MX = 2e5+3;
int n;
int h[MX];
ll a[MX];

ll bit[MX];
void update(int p, ll x) {
    for(; p < MX; p+=p&-p) {
        chmax(bit[p], x);
    }
}

ll get(int p) {
    ll res = 0;
    for(; p>0; p-=p&-p) {
        chmax(res, bit[p]);
    }
    return res;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false); //cout << fixed << setprecision(15);
    cin >> n;
    rep(i,n) cin >> h[i];
    rep(i,n) cin >> a[i];

    rep(i,n) {
        update(h[i], get(h[i])+a[i]);
    }

    cout << get(MX-1) << endl;
    return 0;
}
