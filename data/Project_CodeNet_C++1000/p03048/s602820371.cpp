#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000

int MOD=1000000007;
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
signed main() {
  int r,g,b,n;
  cin>>r>>g>>b>>n;
  int ans=0;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      if(n-r*i-g*j>=0&&(n-r*i-g*j)%b==0){
        ans++;
      }
    }
  }
  cout<<ans<<endl;
}
