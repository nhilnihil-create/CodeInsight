#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//const int INF=1e9,MOD=1e9+7;
const ll LINF=1e18;
using namespace std;
#define int long long
//template
const int MOD=998244353;
std::vector<int> v(1000000);
std::vector<int> w(1000000);
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
  int res=v[n];
  res*=w[k];res%=MOD;
  res*=w[n-k];res%=MOD;
  return res;
}
//main
signed main(){
  int N,A,B,K;cin>>N>>A>>B>>K;
  v[0]=1;for(int i=1;i<1000000;i++)v[i]=v[i-1]*i%MOD;
  for(int i=0;i<1000000;i++)w[i]=pw(v[i],MOD-2);
  int ans=0;
  for(int a=0;a<=N;a++){
    if(K-A*a<0)break;
    if((K-A*a)%B)continue;
    int b=(K-A*a)/B;
    if(b>N)continue;
    ans+=nCk(N,a)*nCk(N,b);
    ans%=MOD;
  }
  cout<<ans<<endl;
}
