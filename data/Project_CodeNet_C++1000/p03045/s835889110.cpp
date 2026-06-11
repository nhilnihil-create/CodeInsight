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
#define fo(i,j,n) for (int i=(j); i < (n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){ 
    int n, m; cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i, m){
        int x, y, z; cin >> x >> y >> z; x--, y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    vector<bool> seen(n, false);
    queue<int> que;
    int res = 0;
    rep(i, n){
        if(seen[i]) continue;
        seen[i] = true; res++;
        que.push(i);
        while(!que.empty()){
            int v = que.front(); que.pop();
            for(int e: G[v]){
                if(seen[e]) continue;
                seen[e] = true;
                que.push(e);
            }
        }
    }
    cout << res << ln;
}