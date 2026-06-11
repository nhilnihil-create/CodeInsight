#include<iostream>
using namespace std;
typedef long long ll;
int main(){
  ll n,m;
  cin>>n>>m;
  ll ans=-1;
  for(ll i=1;i*i<=m;i++){
    if(m/i>=n && m%i==0)
      ans = max(ans,i);
    if(i>=n && m%i==0)
      ans = max(ans,m/i);
  }
  cout<<ans<<endl;
  return 0;
}