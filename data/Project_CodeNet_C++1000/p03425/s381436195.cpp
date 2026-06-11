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
  vector<string>s(n);
  rep(i,n)cin>>s[i];
  sort(s.begin(),s.end());
  vector<char>m={'M','A','R','C','H'};
  vector<int>a(5);
  rep(i,5)if(s[0][0]==m[i])a[i]++;
  rep(i,n-1){
    rep(j,5)if(s[i+1][0]==m[j]&&s[i]!=s[i+1])a[j]++;
  }
  int ans=0;
  rep(i,3){
    for(int j=i+1;j<4;j++){
      for(int k=j+1;k<5;k++){
        ans+=a[i]*a[j]*a[k];
      }
    }
  }
  cout<<ans<<endl;
}
