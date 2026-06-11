#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979;
const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};

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
  ll N, M;
  cin >> N >> M;
  vector<ll> V = enum_div(M);
  V.push_back(M);
  sort(V.begin(), V.end());
  reverse(V.begin(), V.end());
  for (int i=0; i<(int)V.size(); i++) {
    if (V[i]*N<=M) {
      cout << V[i] << endl;
      return 0;
    }
  }
}