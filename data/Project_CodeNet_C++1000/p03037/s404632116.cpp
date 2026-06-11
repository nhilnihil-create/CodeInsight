#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  ll b;
  cin>>b;
  vector<ll>vec(b);
  vector<ll>veco(b);
  for(ll i=0;i<b;i++){
    cin>>vec.at(i)>>veco.at(i);
  }
  sort(vec.begin(),vec.end());
  sort(veco.begin(),veco.end());
  ll d=0;
  cout<<max(veco.at(0)-vec.at(b-1)+1,d)<<endl;
  return 0;
}
