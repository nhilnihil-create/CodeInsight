#include <bits/stdc++.h>
const int INF=1e9,MOD=1e9+7;
const long long LINF=1e18;
using namespace std;
#define int long long
//template
std::vector<int> w(1000000),wm(1000000);
int pw(int n,int k){
  int res=1;
  while(k){
    if(k%2)res*=n;res%=MOD;
    k/=2;
    n*=n;n%=MOD;
  }
  return res;
}
int nCk(int n,int k){
  int res=w[n];
  res*=wm[n-k];res%=MOD;
  res*=wm[k];res%=MOD;
  return res;
}
//main
signed main(){

  w[0]=1;for(int i=1;i<1000000;i++)w[i]=w[i-1]*i%MOD;
  for(int i=0;i<1000000;i++)wm[i]=pw(w[i],MOD-2);

  int N;cin>>N;
  std::vector<int> v(N);
  for(int i=0;i<N;i++)cin>>v[i];

  std::vector<int> p(N);
  for(int i=0;i<N;i++)p[i]=((nCk(N,i+1)*w[i])%MOD*w[N-i-1])%MOD;
  for(int i=1;i<N;i++){
    p[i]+=p[i-1];p[i]%=MOD;
  }
  int ans=0;
  for(int i=0;i<N;i++){
    ans+=v[i]*(p[N-1-i]+p[i]-w[N]+MOD)%MOD;
    ans%=MOD;
  }
  cout<<ans<<endl;
}
