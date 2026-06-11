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
  vector<int>furui(55556,1);
  furui[0]=0;
  furui[1]=0;
  for(int i=2;i<=furui.size()-1;i++){
    if(furui[i]==1){
      for(int j=2*i;j<=furui.size()-1;j=j+i){
        furui[j]=0;
      }
    }
  }
vector<int>ans(0);
  for(int i=1;i<furui.size();i++){
    if(i%10==1&&furui[i]==1)ans.push_back(i);
  }
  rep(i,n)cout<<ans[i]<<' ';

  }
