#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    int n; cin >> n;
    map<int, int> D, T;
    rep(i, n){
        int d; cin >> d; D[d]++;
    }
    int m; cin >> m;
    bool ok = true;
    rep(i, m){
        int t; cin >> t;
        if(D[t] <= 0){
            ok = false; break;
        }
        D[t]--;
    }
    if(ok) cout << "YES" << ln;
    else cout << "NO" << ln;   
}
