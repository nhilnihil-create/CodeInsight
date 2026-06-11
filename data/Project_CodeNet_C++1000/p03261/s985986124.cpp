#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1000000000100000000;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n; cin >> n;
    vector<string> W(n); map<string, bool> mp;
    bool fg = true;
    rep(i, n){
        cin >> W[i];
        if(mp[W[i]])fg = false;
        mp[W[i]] = true;
    }
    rep(i, n-1){
        if(W[i+1][0] != W[i].back())fg = false;
    }
    if(fg)cout << "Yes" << ln;
    else cout << "No" << ln;
}