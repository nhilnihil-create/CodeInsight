#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;

const int mx=100010;
const ll mod=1e9+7;

int n,m,par[mx],dist[mx];
vector<int> v[mx], inv[mx];

void dfs(int x,int p){
  par[x] = p;
  for(auto to:v[x]){
    if(to==p)continue;
    if(dist[to]==dist[x]+1){dfs(to,x);}
  }  
}

int main(){
  cin >> n >> m;
  for(int i=0; i<(n-1+m); i++){
    int a,b;
    cin >> a >> b;
    v[a].push_back(b);
    inv[b].push_back(a);
  }
  
  queue<int> que;
  vector<int> sz(n+5);
  int root;
  
  for(int i=0; i<n; i++){
    sz[i+1]=inv[i+1].size();
    if(inv[i+1].empty()){		//root?
      que.push(i+1);
      root=i+1;
    }
  }
  
  while(!que.empty()){
    int x = que.front(); que.pop();
    for(auto to:v[x]){
      dist[to] = max(dist[x]+1, dist[to]);
      sz[to]--;
      if(sz[to] == 0){que.push(to);}			//second oya
    }
  }
  
  dfs(root,0);  
  for(int i=1; i<=n; i++){
    cout << par[i] << endl;
  }
  return 0;
}