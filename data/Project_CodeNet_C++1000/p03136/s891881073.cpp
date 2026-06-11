#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  vector<ll>vec(a);
  ll b=0;
  for(ll i=0;i<a;i++){
    cin>>vec.at(i);
    b+=vec.at(i);
  }
  sort(vec.begin(),vec.end());
  if(b-vec.at(a-1)>vec.at(a-1)){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
  
  return 0;
}
