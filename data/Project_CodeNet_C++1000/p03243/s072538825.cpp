#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n; cin >> n;
  ll ans;
  for(ll i = n; i<(n+111); i++){
    ll a = i/100; //100
    ll b = i%100; 
    ll c = b/10; //10
    ll d = b%10; //1
    if(a==c && c==d){
      ans+=i;
    }
  }
  cout << ans << endl;
  
  return 0;
}