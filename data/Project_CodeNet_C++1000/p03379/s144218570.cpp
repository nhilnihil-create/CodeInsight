#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> x(n);
  rep(i,n) { cin >> x[i]; }
  vector<int> sorted(n);
  sorted = x;
  sort(sorted.begin(), sorted.end());
  int cl = sorted[(n-1)/2];
  int cr = sorted[(n-1)/2+1];
  rep(i,n) {
    if (x[i] <= cl) cout << cr << endl;
    else cout << cl << endl;
  }
  return 0;
}