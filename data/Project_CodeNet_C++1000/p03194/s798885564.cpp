#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
using namespace std;
typedef long long ll;

typedef pair<ll,ll> P;

bool is_prime(ll n){
  for(ll i = 2; i * i<=n; i++){
    if(n%i==0) return false;
  }
  return n!=1;
}

int main(){
  ll n,p;
  cin >> n >> p;
  if(n==1){
    cout << p << endl;
    return 0;
  }
  ll ans = 1;
  for(ll i = 2; i*i<=p; i++){
    if(!is_prime(i)) continue;
    ll cnt = 0;
    while(p%i==0){
      p = p/i;
      cnt++;
      if(cnt%n==0) ans *= i;
    }
  }
  cout << ans << endl;
  return 0;
}
