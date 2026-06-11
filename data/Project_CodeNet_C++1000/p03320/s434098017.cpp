#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll tpw(int a){
  ll b=1;
  for(int i=0;i<a;i++)
    b*=10;
  return b;
}

int S(ll a){
  int b=0;
  while(a){
    b+=a%10;
    a/=10;
  }
  return b;
}

int main(){
  int K; cin>>K;
  ll ans=0;
  ll cg=1;
  vector<ll> A;
  for(int i=0;K;i++){
    ans+=cg;
    if(ans>cg*S(ans)){
      ans+=9*cg;
      cg*=10;
    }
    cout<<ans<<endl;
    K--;
  }
}