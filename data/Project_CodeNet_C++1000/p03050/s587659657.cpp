#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  ll n;
  cin>>n;
  ll ans=0;
  if(n<3){
    cout<<"0"<<endl;
    return 0;
  }
  ans+=n-1;
  for(ll i=1;i*i < n;i++){
    if(i==1){
      continue;
    }
    if(n%i==0&&i*(i+1)!=n){
      ans+=n/i;
      ans--;
    }
  }
  cout<<ans<<endl;
}
