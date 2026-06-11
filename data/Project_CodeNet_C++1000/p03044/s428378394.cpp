#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n);++i)
const int INF =1001001001;
using ll=long long;
using Edge = pair<ll,ll>;
using Graph =vector<vector<Edge>>;
vector<int> color;
Graph G;
vector<int> ans;
ll N;
void dfs(ll i, ll j=-1){
    for(auto u : G[i]){
        if(u.first == j) continue;
        if(u.second % 2 == 0){
            color[u.first] = color[i];
        }else{
            color[u.first] = -color[i];
        }
        dfs(u.first, i);
    }
}
int main() {
cin>>N;
G.resize(N);
rep(i,N-1){
  ll a,d,c;
  cin>>a>>d>>c;
  --a;
  --d;
  G[a].push_back(Edge(d,c));
  G[d].push_back(Edge(a,c));
}
   ans.resize(N);
    ans[0] = 1;
color.resize(N,-1);
color[0]=1;
dfs(0);
    rep(i,N){
        if(color[i]==-1) cout << '0' << endl;
        else if(color[i]==1) cout << '1' << endl;
    }
return 0;
}