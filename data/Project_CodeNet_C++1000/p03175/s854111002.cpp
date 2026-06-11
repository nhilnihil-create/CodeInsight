#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (1e9)
#define INFL (1e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>using arr=vector<vector<T>>;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int n;
arr<int> G;
vector<bool> seen;
arr<ll> dp;

void dfs(int s, int p){
    // pr(s);
    seen[s] = true;
    if(p != -1 && G[s].size()==1){
        dp[s][0] = 1;
        dp[s][1] = 1;
    }else{
        for(int i: G[s]){
            if(seen[i]) continue;
            dfs(i, s);
        }

        ll white = 1, black = 1;
        for(int i: G[s]){
            if(i==p) continue;
            // 0は黒
            white *= (dp[i][0] + dp[i][1]);
            white %= MOD;
            black *= (dp[i][1]);
            black %= MOD;
        }

        dp[s][0] = black;
        dp[s][1] = white;
    }
    // prarr(dp);
}

int main()
{
    cin >> n;
    G.resize(n);
    rep(i, n-1){
        int x, y; cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dp.assign(n, vector<ll>(2, 1));
    seen.assign(n, false);
    dfs(0, -1);
    
    pr((dp[0][0] + dp[0][1])%MOD);
    return 0;}