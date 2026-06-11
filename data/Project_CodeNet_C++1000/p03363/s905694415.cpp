#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;
using ll = long long int;
int main(){
  ll n;
  cin >> n;
  map<ll, ll> ANS;
  vector<ll> SUM(n, 0LL);
  
  for(ll i=0;i<n;i++){
    ll vi;
    cin >> vi;
    if(i!=0)
      SUM[i] = SUM[i-1];
    SUM[i] += vi;
  }
  
  for(auto e: SUM){
    {
      ANS[e]++;
    }
  }
  
  ll ans=0;
ANS[0]+=1;
  for(auto e:ANS){
      ans += e.second*(e.second-1)/2;
  }
  cout<<ans<<endl;

}
