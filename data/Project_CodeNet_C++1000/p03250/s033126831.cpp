#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  vector<ll>vec(3);
  ll b=0;
  for(ll i=0;i<3;i++){
    cin>>vec.at(i);
    b+=vec.at(i);
  }
  sort(vec.begin(),vec.end());
  b+=9*vec.at(2);
  cout<<b<<endl;
  return 0;
}
