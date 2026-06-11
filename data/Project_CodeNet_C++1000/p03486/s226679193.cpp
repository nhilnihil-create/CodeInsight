#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  string s, t;
  cin >> s >> t;

  vector<char> S;
  rep(i,s.size()) S.push_back(s[i]);
  sort(S.begin(), S.end());

  string ss = "";
  rep(i,S.size()) ss += S[i];

  vector<char> T;
  rep(i,t.size()) T.push_back(t[i]);
  sort(T.begin(), T.end());
  reverse(T.begin(), T.end());

  string tt = "";
  rep(i,T.size()) tt += T[i];

  if (ss < tt) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}