#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
constexpr long long LINF = 1000100010001000100LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() { 
    ll n,  m[5]; cin >> n;
    rep(i, 5) cin >> m[i];
    sort(m, m+5);

    ll res = (n+(m[0]-1))/m[0] + 4;
    cout << res << ln;
}