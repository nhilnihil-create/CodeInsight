#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

// 約数列挙 O(√n)
vector<ll> divisor(ll n){
  vector<ll> res;
  for(ll i = 1; i * i <= n; i++){
    if(n % i == 0){
      res.push_back(i);
      if(i != n / i) res.push_back(n / i);
    }
  }
  return res;
}

int main(){
  cout << setprecision(10);
  ll N;
  cin >> N;

  auto m = divisor(N);

  ll ans = 0;
  for(auto x: m){
    ll tmp =  (N / x) - 1;
    if(tmp == 0) continue;

    if( N % tmp == N / tmp){
      ans += tmp;
    }
  }
  cout << ans << endl;
}
