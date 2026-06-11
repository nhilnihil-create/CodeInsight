#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

// 約数全列挙
vector<ll> enum_div(ll n){
  vector<ll> ret;
  for (ll i=1; i*i<=n; i++){
    if (n%i==0){
      ret.push_back(i);
      if (i!=1&&i*i!=n) ret.push_back(n/i);
    }
  }
  return ret;
}

int main() {
  ll N;
  cin >> N;
  vector<ll> div = enum_div(N);
  if (N!=1) div.push_back(N);
  for (int i=1; i<(int)div.size(); i++) div[i]--;
  ll res = 0;
  for (int i=1; i<(int)div.size(); i++) {
    // mの候補を全探索
    if (N/div[i]==N%div[i]) res += div[i];
  }
  cout << res << endl;
  return 0;
}