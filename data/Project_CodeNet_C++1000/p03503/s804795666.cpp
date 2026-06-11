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
  int n;
  cin>>n;
  vector<vector<int>>f(n,vector<int>(10));
rep(i,n){
  rep(j,10)cin>>f[i][j];
}
vector<vector<int>>p(n,vector<int>(11));
rep(i,n){
  rep(j,11)cin>>p[i][j];
}
int ans=-INF;
for(int bit=1;bit<(1<<10);bit++){

int t=0;

    rep(j,n){
          int kaburi=0;
      for(int i=0;i<10;i++){
      if(f[j][i]==1&&(bit&(1<<i)))kaburi++;
    }
    t+=p[j][kaburi];
  }
  ans=max(t,ans);
}
cout<<ans<<endl;
}
