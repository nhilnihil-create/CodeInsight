#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

vector<int> seen;
vector<vector<int>> g;
vector<int> c;
int p=0;

void dfs(int x=0){
  if(seen[x]) return;
  seen[x]=c[p];
  p++;
  for(auto nx:g[x]){
    dfs(nx);
  }
}

int main(){
  int n;
  cin>>n;
  g.resize(n);
  rep(i,n-1){
    int a,b;
    cin>>a>>b;
    a--; b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  c.resize(n);
  rep(i,n) cin>>c[i];
  
  seen.resize(n);
  sort(c.begin(),c.end(),greater<int>());
  
  dfs();
  
  int ans=0;
  rep(i,n-1) ans+=c[i+1];
  cout<<ans<<endl;
  rep(i,n){
    cout<<seen[i]<<" ";
  }
}