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
  int c[n],s[n],f[n];
  rep(i,n-1)cin>>c[i]>>s[i]>>f[i];
  rep(i,n-1){
    int x=s[i]+c[i];
    for(int j=i+1;j<n-1;j++){
      if(x-s[j]<0)x=s[j]+c[j];
      else if((x-s[j])%f[j]==0)x+=c[j];
      else x=f[j]-(x-s[j])%f[j]+x+c[j];
    }
    cout<<x<<endl;
  }
  cout<<0<<endl;
}
