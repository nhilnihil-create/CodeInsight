#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define mp make_pair
ll mod = 10e9+7;
ll mod2 = 998244353;

vector<int> G[100100];
vector<int> M(100100,1);

int dfs(int v){
    if (M[v]==0) return 0;
    M[v] = 0;
    for(auto next_v:G[v]){
        dfs(next_v);
    }
}

int main(){
    int n,m;cin>>n>>m;
    rep(i,0,m){
        int x,y,z;cin>>x>>y>>z;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int ans = 0;
    rep(i,0,n){
        if (M[i]==1){
            ans++;
            dfs(i);
        }
    }
    cout<<ans<<endl;
}