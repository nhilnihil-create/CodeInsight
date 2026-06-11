#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000

int MOD=1000000007;
struct edge {
    int to, cost;
};

int modpow(int a,int x){
  if(a<0)a+=MOD;
  int ans=1;
  while(x>0){
    if(x&1) ans=ans*a%MOD;
      a=a*a%MOD;
      x>>=1;
  }
  return ans;
}

int gyaku(int n){
    return modpow(n,MOD-2);
}

auto factor(int n){
  map<int,int>res;
  for(int i=2;i*i<=n;i++){
      for(; n%i==0;n/=i) res[i]++;
  }
  if(n>1)res[n]++;
  return res;
}
////////////////////////////////////////////////////////////
  vector<vector<edge>>g(100001,vector<edge>(0));
    int n,m;
void dfs(vector<vector<int>>v,vector<int>&dis,int start){
  rep(i,n){
    if(v[start][i]==1){
      if(dis[i]==-1){
        dis[i]=dis[start]+1;
        dfs(v,dis,i);
      }
    }
  }
}
signed main() {
  cin>>n>>m;
  vector<vector<int>>g(n,vector<int>(n));
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--;b--;
    g[a][b]=1;
    g[b][a]=1;
  }
  int ans=0;
  rep(i,n){
    rep(j,n){
      if(g[i][j]==1){
      auto gdash=g;
      gdash[i][j]=0;
      gdash[j][i]=0;
      vector<int>d(n,-1);
      d[0]=0;
      dfs(gdash,d,0);
      rep(k,n){
        if(d[i]==-1){ans++;break;}
      }
    }
  }
}
  cout<<ans<<endl;
}
