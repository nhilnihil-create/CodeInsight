#include<iostream>
using namespace std;
using ll=long long;

int N,K;
int main(){
  cin>>N>>K;
  ll ans=0;
  for(int b=1;b<=N;b++){
    ans+=max(b-K,0)*(N/b);
    ans+=max(N%b-K+1,0);
  }
  if(K==0) ans-=N;
  cout<<ans<<endl;
  return 0;
}