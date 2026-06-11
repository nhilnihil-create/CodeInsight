#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

vector<P> to[100010];
vector<int> ans;

void dfs(int i, int p=-1){
  for(auto x : to[i]){
    if(x.first==p) continue;
    if(x.second%2==0){
      if(ans[i]==0) ans[x.first]=0;
      else ans[x.first]=1;
    }else{
      if(ans[i]==0) ans[x.first]=1;
      else ans[x.first]=0;
    }
    dfs(x.first,i);
  }
}

int main(){
  int n;
  cin>>n;
  rep(i,n-1){
    int u,v,w;
    cin>>u>>v>>w;
    u--; v--;
    to[u].push_back(make_pair(v,w));
    to[v].push_back(make_pair(u,w));
  }
  ans.resize(n);
  dfs(0);
  rep(i,n) cout<<ans[i]<<endl;
}