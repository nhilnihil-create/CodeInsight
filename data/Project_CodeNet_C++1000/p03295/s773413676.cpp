#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1e18 + 10;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main(){ 
    int n, m; cin >> n >> m;
    priority_queue<pii, vector<pii>, greater<pii>> que;
    rep(i, m){
        int a, b; cin >> a >> b;
        que.push({b, a});
    }

    int res = 0, fall = -1;
    while(!que.empty()){
        auto p = que.top(); que.pop();
        int a = p.second, b = p.first;
        if(a <= fall)continue;
        fall = b-1;
        res++;
    }
    cout << res << ln;
}