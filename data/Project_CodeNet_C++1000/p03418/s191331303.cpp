#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 5000
#define MOD 1000000007

int main(){
  ll N,K;
  cin>>N>>K;
  ll ans=0;
  if(K==0){
    cout<<N*N<<endl;
  }else{
    for(ll b=K+1;b<=N;b++){
      ll x=N/b;
      ans+=x*(b-K);
      ans+=max<ll>(0,N-b*x-K+1);
    }
    cout<<ans<<endl;
  }
}
