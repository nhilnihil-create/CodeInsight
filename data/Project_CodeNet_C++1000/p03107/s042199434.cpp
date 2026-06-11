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
  stack<char> S;
  rep(i,n) {
    if (S.empty() || S.top() == s[i]) S.push(s[i]);
    else {
      ans += 2;
      S.pop();
    }
  }
  cout << ans << endl;
  return 0;
}