#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  int n,m;cin>>n>>m;
  vector<vector<int>>g(n), rg(n);
  vector<int> in_count(n);
  rep(i, n-1+m){
    int a,b; cin>>a>>b; a--;b--;
    g[a].push_back(b);
    rg[b].push_back(a);
    in_count[b]++;
  }

  vector<int> sorted_nodes;
  queue<int> count0;
  rep(i, n)if(in_count[i]==0)count0.push(i);
  int root = count0.front();
  while(count0.size()){
    int p = count0.front();count0.pop();
    sorted_nodes.push_back(p);
    for(auto c:g[p]){
      in_count[c]--;
      if(in_count[c]==0)count0.push(c);
    }
  }

  vector<int>parent(n);

  for(auto c:sorted_nodes){
    for(auto chi: g[c]){
      parent[chi]=c;
    }
  }

  parent[root]=-1;

  rep(i, n)cout<<parent[i]+1<<endl;

  return 0;
}
