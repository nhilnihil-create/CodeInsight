#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr int INF = 2e9;

map< ll, int > prime_factor(ll n) {
  map< ll, int > res;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      res[i]++;
      n /= i;
    }
  }
  if(n != 1) res[n] = 1;
  return res;
}

int main(){
  int x;
  cin >> x;
  map<ll, int> sum;

  for (int i = 1; i <= x; i++) {
    auto tmp = prime_factor(i);
    for (auto e : tmp) sum[e.first] += e.second;
  }

  vector<int> dp(77);
  dp[1] = 1;

  for (auto e : sum) {
    vector<int> ndp(77);
    for (int i = 0; i < 76; i++) {
      for (int j = 0; j <= e.second; j++) {
        ndp[min(76, i * (j + 1))] += dp[i];
      }
    }
    swap(dp, ndp);
  }
  cout << dp[75] << endl;
  return 0;
}