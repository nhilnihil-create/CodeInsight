#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

ll sum[202020], X[202020];

int main(){
  int N; cin>>N;
  ll A; cin>>A;
  rep(i,N){
    cin>>X[i];
    sum[i+1]=sum[i]+X[i];
  }
  if(N==1){
    cout<<2*A+X[0]<<endl;
    return 0;
  }
  ll ans=1e17;
  for(int i=1;i<=(N+1)/2;i++){
    ll tmp=(N+i)*A+5*(sum[N]-sum[max(0,N-i*2)]);
    if(tmp<0) continue;
    ll y=7;
    for(int j=N-i*2;j>=1;j-=i){
      tmp+=y*(sum[j]-sum[max(0,j-i)]);
      y+=2;
    }
    if(tmp<0) continue;
    ans=min(ans,tmp);
  }
  cout<<ans<<endl;
  return 0;
}
