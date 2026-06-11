#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  set<int> a;
  int min_a = 1e9+5;
  rep(i,n) {
    int ai; cin >> ai;
    min_a = min(min_a, ai);
    a.insert(ai);
  }
  while (a.size() > 1) {
    int min_na = min_a;
    for (auto ai : a) {
      if (min_a == ai) continue;
      a.erase(ai);
      int na = ai % min_a;
      if (na != 0) {
        a.insert(na);
        min_na = min(min_na, na);
      }
    }
    min_a = min_na;
  }
  cout << min_a << endl;
  return 0;
}