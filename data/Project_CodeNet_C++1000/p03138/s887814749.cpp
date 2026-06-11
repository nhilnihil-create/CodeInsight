#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll N,K;
int main(){
  cin>>N>>K;
  vector<ll>A(N);
  for(ll i=0;i<N;i++)
    cin>>A[i];
  ll a=1;
  if(K==0){
  ll ans=0;
    for(ll i=0;i<N;i++)
      ans+=(0^A[i]);
    cout<<ans<<endl;
  }else{
  while(a<=K)a*=2; a/=2;
  ll sum=0;
  while(1){
  ll sum1=0;ll sum2=0;
    for(ll i=0;i<N;i++){
    sum1+=(a^A[i]);
      sum2+=(0^A[i]);
    }
      if(sum2<=sum1 && sum+a<=K)sum+=a;
      if(a==1)break;
      else
        a/=2;
      }ll ans=0;
    for(ll i=0;i<N;i++)
      ans+=(sum^A[i]);
    cout<<ans<<endl;
  }
  return 0;
}