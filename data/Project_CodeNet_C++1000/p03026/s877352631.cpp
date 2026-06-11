#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

vector<ll> c, ans;
vector<vector<ll>> graph;
int pt=0;

void dfs(int s, int f){
  for(auto p:graph[s]){
    if(p!=f)dfs(p, s);
  }
  ans[s] = c[pt];
  pt++;
}

int main(){
  int n;cin>>n;

  ll a[n-1],b[n-1];
  rep(i,n-1)cin>>a[i]>>b[i];

  graph.resize(n+1);
  rep(i,n-1){
    graph[ a[i] ].push_back( b[i] );
    graph[ b[i] ].push_back( a[i] );
  }

  c.resize(n);
  ans.resize(n+1);
  rep(i, n)cin>>c[i];
  sort(c.begin(), c.end());

  dfs(1, -1);

  int sum=0;
  rep(i, n-1)sum+=c[i];
  cout<<sum<<endl;

  rep(i,n)cout<<ans[i+1]<<' ';
  cout<<endl;

  return 0;
}