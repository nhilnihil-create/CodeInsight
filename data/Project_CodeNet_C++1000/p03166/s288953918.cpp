#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<vector<int> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

Graph G;
int dp[100010];

int rec(int v){
    if(dp[v]!=-1)return dp[v];
    int res = 0;
    for(int nv:G[v]){
        chmax(res,rec(nv)+1);
    }
    return dp[v]=res;
}

int main(){
    int n,m;
    cin >> n >> m;
    G.resize(n);
    rep(i,m){
        int x,y;
        cin >> x >> y;
        x--;y--;
        G[x].push_back(y);
    }

    rep(i,n){
        dp[i]=-1;
    }
    int ans = 0;
    rep(i,n){
        chmax(ans,rec(i));
    }
    cout << ans << endl;
    return 0;
}
