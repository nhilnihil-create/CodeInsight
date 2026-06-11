#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vl>;  // vi <=> vl
using P = pair<int, int>;  // int <=> ll
const int MOD = 1e9+7;
const double EPS = 1e-9;

int main() {
  string S;
  cin >> S;
  Graph ABC(S.size()+1, vl(3,0));  // 1-indexed
  ll count = 1;
  rep(i,S.size()) {
    ABC[i+1] = ABC[i];
    if (S[i] == 'A') (ABC[i+1][0] += count) %= MOD;
    else if (S[i] == 'B') (ABC[i+1][1] += ABC[i][0]) %= MOD;
    else if (S[i] == 'C') (ABC[i+1][2] += ABC[i][1]) %= MOD;
    else {
      ((ABC[i+1][0] *= 3) += count) %= MOD;
      ((ABC[i+1][1] *= 3) += ABC[i][0]) %= MOD;
      ((ABC[i+1][2] *= 3) += ABC[i][1]) %= MOD;
      (count *= 3) %= MOD;
    }
  }
  cout << ABC[S.size()][2] << endl;
  return 0;
}
