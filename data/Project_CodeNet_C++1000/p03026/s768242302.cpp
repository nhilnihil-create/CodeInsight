#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;

const int MOD=1000000007;
int INF=100100100100100;

vector<int> g[10010];
int depth[10010];
int c[10010];
int ans[10010];
int sum=0;
priority_queue<P> que;
void dfs(int v,int p=-1){
  //par[v]=p;
  if(p<0){
    depth[v]=0;
    que.push(P(depth[v],v));
  }
  else {
    depth[v]=depth[p]+1;
    que.push(P(depth[v],v));
  }
    
  int res=0;
  for(int w:g[v]){
    if(w!=p){
      dfs(w,v);
    }
  }
}
signed main(){
  int n;cin>>n;
  rep(i,n-1){
    int a,b;cin>>a>>b;
    a--;b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  rep(i,n)cin>>c[i];
  sort(c,c+n);
  dfs(0);
  int ima=0;
  while(!que.empty()){
    P p=que.top();que.pop();
    ans[p.S]=c[ima];
    if(p.F!=0)sum+=c[ima];
    ima++;
  }
  cout<<sum<<endl;
  rep(i,n)cout<<ans[i]<<endl;
  return 0;
}