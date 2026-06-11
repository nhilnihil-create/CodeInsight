#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b; cin >> a >> b;
  string s; cin >> s;
  rep(i,s.size()) {
    if (i < a && s[i] == '-') {
      cout << "No" << endl;
      return 0;
    }
    if (i == a && s[i] != '-') {
      cout << "No" << endl;
      return 0;
    }
    if (a+1 < i && s[i] == '-') {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}