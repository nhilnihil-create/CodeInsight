#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  string ans = "Yes";
  vector<string> w(n);
  vector<int> wn(n);
  set<string> ws;
  rep(i,n) {
    cin >> w[i];
    wn[i] = w[i].size();
    if (i!=0 && w[i-1][wn[i-1]-1] != w[i][0] ||
        ws.count(w[i]) != 0) {
      ans = "No";
      break;
    }
    ws.insert(w[i]);
  }
  cout << ans << endl;

  return 0;
}