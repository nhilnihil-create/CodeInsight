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
signed main() {
  int h,w;
  cin>>h>>w;
  int c[10][10];
  rep(i,10)rep(j,10){cin>>c[i][j];}
  rep(k,10){
    rep(i,10){
      rep(j,10){
        c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
      }
    }
  }
  int ans=0;
  rep(i,h){
    rep(j,w){
      int a;cin>>a;
      if(a!=-1)ans+=c[a][1];
    }
  }
cout<<ans<<endl;
}
