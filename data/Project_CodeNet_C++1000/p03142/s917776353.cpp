#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

const int n_max=1e5+5;
vector<pair<int, int> > g[n_max];//どこに、used
vector<int > rg[n_max];
bool used[n_max];
int tp;
int ans[n_max];
int dep[n_max];

void dfs_leaf(int v){
  if(!used[v]){
    used[v]=true;
    for(auto i:g[v]){
      if(!used[i.first]) dfs_leaf(i.first);
    }
  }
}

void dfs_par(int v){
  if(!used[v]){
    tp=v;
    used[v]=true;
    for(auto i:g[v]){
      if(!used[i.first]) dfs_leaf(i.first);
    }
  }
}

/*void dfs_ans(int v, int d){
  int j=0;
  dep[v]=d+1;
  for(auto i:g[v]){    
    if(i.second==0){
      g[v][j]=mp(i.first, 1);
      if(dep[i.first] < d+1){
	ans[i.first]=v+1;
      }
      cout << "from" << v << " to " <<i.first << endl;
      dfs_ans(i.first, d+1);
    }
    j++;
  }
  }*/

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;
  int a,b;
  rep(i,n+m-1){
    cin >> a >> b;
    a--;b--;
    g[a].pb(mp(b,0));
    rg[b].pb(a);
  }
  rep(i,n) used[i]=false;
  rep(i,n){
    dfs_par(i);
  }
  rep(i,n) dep[i]=0;
  //  cout << "par " << tp << endl;
  ans[tp]=0;
  int cou[n];
  rep(i,n) cou[i]=0;
  cou[tp]=-1;
  queue<int> qu;
  qu.push(tp);
  while(!qu.empty()){
    int v=qu.front();qu.pop();
    cou[v]++;
    if(rg[v].size()!=cou[v]) continue;
    for(auto i:g[v]){      
      qu.push(i.first);
      ans[i.first]=v+1;
    }
  }
  rep(i,n) cout << ans[i] << endl;



  
  return 0;
    

}
