#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  string s, t; cin >> s >> t;
  map <char, ll> score_s, score_t;
  vector <ll> res_s(s.size()), res_t(t.size());
  rep(i, s.size()) {
    if (!score_s.count(s.at(i))) score_s[s.at(i)] = score_s.size();
    res_s.at(i) = score_s.at(s.at(i));
    if (!score_t.count(t.at(i))) score_t[t.at(i)] = score_t.size();
    res_t.at(i) = score_t.at(t.at(i));
  }
  if (res_s == res_t) cout << "Yes" << endl;
  else cout << "No" << endl;
}