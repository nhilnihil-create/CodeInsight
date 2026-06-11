#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
  ll n;
  cin>>n;
  //vector<ll> a;
  ll ans;
  for(ll i=1;i*i<=n;i++){
    if((i+1)*(i+1)>n) ans=i*i;
  }
  cout<<ans<<endl;
}