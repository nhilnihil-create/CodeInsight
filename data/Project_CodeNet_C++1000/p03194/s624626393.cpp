#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

map< ll, int > prime_factor(ll n) {
  map< ll, int > ret;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

int main(){
  ll n,p;
  cin >> n >> p;
  map<ll,int> mp = prime_factor(p);
  ll ans=1;
  for(auto p:mp){
    if(p.second>=n)ans*=pow(p.first,p.second/n);
  }
  cout << ans << endl;
}
