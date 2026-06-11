#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define rep1(i,n) for (int i=1; i<=(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define fst first
#define scd second
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s; cin >> s;
  int n = s.size(), ans = 0;
  stack<char> S,T;
  rep(i,n) S.push(s[n-1-i]);
  while(!S.empty()) {
    char si = S.top(); S.pop();
    if (!S.empty() && si != S.top()) {
      S.pop();
      ans += 2;
    } else {
      T.push(si);
    }
    while (!T.empty() && !S.empty() && T.top() != S.top()) {
      T.pop(); S.pop();
      ans += 2;
    }
  }
  while (!T.empty()) {
    char ti = T.top(); T.pop();
    if (!T.empty() && T.top() != ti) {
      T.pop();
      ans += 2;
    }
  }
  cout << ans << endl;
  return 0;
}