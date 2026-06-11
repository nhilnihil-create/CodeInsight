#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  vector<ll>vec(a);
  for(ll i=0;i<a;i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(),vec.end());
  cout<<vec.at(a-1)-vec.at(0)<<endl;
  return 0;
}
