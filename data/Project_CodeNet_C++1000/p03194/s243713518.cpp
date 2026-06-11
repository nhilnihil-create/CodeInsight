#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  ll n, p;
  cin >> n >> p;

  int m = sqrt(p);
  vector<ll> d(m+2);
  rep(i,m+2) d[i]=0;

  ll j = 2;
  while(1){
    if(p%j == 0){
      p /= j;
      d[j]++;
      continue;
    }
    j++;
    if(j > m+1) break;
  }

  ll ans = 1;
  for(int i = 2; i <= m+1; i++) {
    ll k = d[i]/n;
    while(k>0) {
      ans *= i;
      k--;
    }
    //cout << i << " " << d[i] << endl;
  }
  if(1/n == 1) ans *= p;
  
  cout << ans << endl;
  
}
