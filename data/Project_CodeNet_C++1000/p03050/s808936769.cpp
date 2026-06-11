#include<bits/stdc++.h>
using namespace std;
using ll=long long;


int main(){
  ll n;
  cin >> n;
  vector<ll> re;
  ll ans=0;
  for(ll i=1;i*i<=n;++i){
    if(n%i==0){
      re.push_back(i);
      //ans+=(i-1);
      if(i*i!=n){
        re.push_back(n/i);
        //ans+=(n/i-1);
      }
    }
  }
  sort(re.begin(),re.end());
  for(int i=1;i<re.size();++i){
    if(re[i]==2)continue;
    if((n/(re[i]-1))==n%(re[i]-1)){
      ans+=re[i]-1;
    }
  }
  cout << ans << endl;
  return 0;
}
