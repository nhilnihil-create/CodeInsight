#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define INF 1000000000
#define MAX_N 300000
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
bool used[MAX_N];
vector<int> G[MAX_N];
int tree_dfs(int v,int& last_v,int& leng_v,int cnt){
  used[v]=true;
  if(leng_v<cnt){
    leng_v = cnt;
    last_v = v;
  }
  int res=cnt,tmp;
  for(auto to:G[v]){
    if(!used[to]){
      tmp = tree_dfs(to,last_v,leng_v,cnt+1);
      res = max(tmp,res);
    }
  }
  return res;
}
ll tree_size(int n,vector<int> G[],bool used[]){
  int u,nu,lv;
  fill(used,used+n,false);
  u=lv=0;
  tree_dfs(0,u,lv,0); 
  lv=0;
  nu = u;
  fill(used,used+n,false);
  return tree_dfs(u,nu,lv,0); 
}
signed main(){
  int n;
  cin >> n;
  ll a[n],b[n];
  for(int i=0;i<n-1;i++){
    cin >> a[i]>>b[i];
    a[i]--;
    b[i]--;
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
  }
  ll v=tree_size(n,G,used);
  if(v%3==1){
    cout <<"Second\n";
  }else{
    cout <<"First\n";
  }
}
