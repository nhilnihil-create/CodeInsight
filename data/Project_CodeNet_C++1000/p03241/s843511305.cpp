#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i = 1; i < (int)(n); i++)

vector<ll> divisor(ll n) {
  vector<ll> res;
  for(ll i = 1; i * i <= n; i++) {
    if(n%i == 0) {
      res.emplace_back(i);
      if(i != n / i) res.emplace_back(n / i);
    }
  }
  return res;
}

int main() {
  int n,m;
  cin >> n >> m;
  int ans = 1;
  vector<ll>div = divisor(m);
  sort(div.begin(),div.end());
  rep(i,div.size()){
    if(div[i] > m/n) break;
    if(m/div[i] >= n) ans = div[i];
  }
  cout << ans << endl;
}