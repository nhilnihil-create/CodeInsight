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


int main(){
    int n; cin >> n;
    vector<vector<int>> Q;

    int cx = 0, cy = 0, bt = 0;bool fg = true;
    rep(i, n){
        int t, x, y; cin >> t >> x >> y;
        int dist = abs(x-cx) + abs(y-cy), time = t - bt;
        if(dist > time || dist%2 != time%2){
            fg = false; break;
        }
        bt = t; cx = x; cy = y;    
    }
    if(fg) cout << "Yes" << ln;
    else cout << "No" << ln;
}
