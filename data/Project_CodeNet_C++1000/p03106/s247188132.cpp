#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  ll a,b;
  cin>>a>>b;
  ll c=min(a,b);
  ll k;
  cin>>k;
  ll g=0;
  vector<ll>vec(0);
  for(ll i=1;i<=c;i++){
    if(a%i==0&&b%i==0){
      vec.push_back(i);
      g+=1;
      }
    }
  cout<<vec.at(g-k)<<endl;
}