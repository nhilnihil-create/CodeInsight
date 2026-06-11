#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
#define PI 3.14159265359
#define MOD 998244353
const int MAX = 510000;

int main() {
  int N;cin>>N;
  map<ll,ll>C;
  rep(i,N){
  	ll a;cin>>a;
    C[a]++;
  }  
  ll ans=0;
 for (auto p :C) {
  auto key = p.first;
  auto value = p.second;
  if(key<=value){ans+=(value-key);}
  else{ans+=value;} 
 }
  cout<<ans;
}