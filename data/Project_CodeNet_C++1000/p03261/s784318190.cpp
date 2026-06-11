#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int n;
bool ans = true;

int main() {
  cin >> n;
  vector<string> w(n);
  rep (i, n) {
    cin >> w[i];
  }
  rep (i, n-1) {
    if (w[i][w[i].size()-1] != w[i+1][0]) ans = false;
  }
  sort(w.begin(), w.end());
  rep (i, n-1) {
    if (w[i] == w[i+1]) ans = false;
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
