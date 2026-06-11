#include <bits/stdc++.h>

#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int INF = pow(2,29);
const int MOD = 1000000007;

int main() {
  string s; cin >> s;
  int l = s.length();

  vector<int> pos;
  rep(i, l-1) {
    if (i==0 && s[i]=='0') { cout << -1 << endl; return 0; }
    if (s[i]!=s[l-2-i]) { cout << -1 << endl; return 0; }
    if (s[i]=='1') pos.push_back(i+1);
  }
  if (s[l-1]=='0') pos.push_back(l);
  else { cout << -1 << endl; return 0; }

  rep(i, pos.size()-1) {
    for (int j=pos[i]; j<pos[i+1]; j++) {
      cout << j << " " << pos[i+1] << endl;
    }
  }
  return 0;
}