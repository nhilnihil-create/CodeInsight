#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> b(n), ans;
  rep(i,n) {
    cin >> b[i];
    b[i]--;
  }
  while(!b.empty()) {
    for (int i = b.size()-1; i>=-1; i--) {
      if (i==-1) {
        cout << -1 << endl;
        return 0;
      }
      if (i == b[i]) {
        ans.push_back(i);
        b.erase(b.begin() + i);
        break;
      }
    }
  }
  for (int i = n-1; i>=0; i--) {
    cout << ans[i] + 1 << endl;
  }
  return 0;
}