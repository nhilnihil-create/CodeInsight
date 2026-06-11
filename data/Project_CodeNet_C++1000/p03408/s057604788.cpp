#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>; 
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1001001001001001001;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n; cin >> n;
    map<string, int> mp;
    rep(i, n){
        string s; cin >> s;
        mp[s]++;
    }
    int m; cin >> m;
    rep(i, m){
        string s; cin >> s;
        mp[s]--;
    }
    int res = -INF;
    for(auto m: mp){
        int score = m.second;
        chmax(res, score);
    }
    chmax(res, 0);
    cout << res << ln;
}
    
