#include<bits/stdc++.h>
using namespace std;
typedef int64_t ll;

int main(){
  ll N;
  cin>>N;
  ll ans=0;
  for(ll i=1;i*i<=N;i++){
    if((N-i)%i==0&&i<(N-i)/i)ans+=(N-i)/i;
  }
  cout<<ans<<endl;
}