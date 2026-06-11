#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  const ll M = 1e9+7;
  int n; string s;
  cin >> n >> s;
  map<char,ll> c;
  rep(i,n) {
    c[s[i]]++;
  }
  ll ans = 1, p = 1, q = 0;
  for (auto ci : c) {
    char k = ci.first;
    int v = ci.second;
    ans = ans * (v+1) % M;
  }
  cout << ans - 1 << endl;

  return 0;
}