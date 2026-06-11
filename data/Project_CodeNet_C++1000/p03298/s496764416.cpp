#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int N; cin >> N;
  string S; cin >> S;
  string ls = S.substr(0,N);
  string rs = S.substr(N,N); reverse(rs.begin(),rs.end());

  map<char, ll> cl, cr;
  rep(i,N) { cl[ls[i]]++; cr[rs[i]]++; }
  bool ok = true;
  for (auto x: cl) {
    if (x.second!=cr[x.first]) ok = false;
  }
  if (!ok) { cout << 0 << endl; return 0; }

  map<string, map<string,ll>> left, right;
  rep(i,(1<<N)) {
    string sl = "", tl = "";
    string sr = "", tr = "";
    rep(j,N) {
      if (i&(1<<j)) { sl += ls[j]; sr += rs[j]; }
      else { tl += ls[j]; tr += rs[j]; }
    }
    left[sl][tl]++; right[sr][tr]++;
  }

  ll result = 0;
  for (auto x: left) for (auto y: x.second) {
    result += y.second * right[x.first][y.first];
  }
  cout << result << endl;
  return 0;
}