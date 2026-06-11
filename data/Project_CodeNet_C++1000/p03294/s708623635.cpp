#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  ll b=0;
  for(ll i=0;i<a;i++){
    ll c;
    cin>>c;
    b+=c;
  }
  cout<<b-a<<endl;
  return 0;
}
