#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s, t; cin >> s >> t;
  deque<char> sq, tq;
  string ans = "No";
  int sn = s.size();
  rep(i,sn) {
    sq.push_back(s[i]);
    tq.push_back(t[i]);
  }
  rep(i,sn) {
    tq.push_front(tq.back());
    tq.pop_back();
    if (sq == tq) ans = "Yes";
  }
  cout << ans << endl;
  return 0;
}