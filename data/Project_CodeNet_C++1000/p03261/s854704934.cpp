#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<string> w(n);
  rep(i, n) {
    cin >> w[i];
  }
  set<string> st;
  st.insert(w[0]);
  bool ok = true;
  for (int i = 1; i < n; i++) {
    if (w[i - 1].back() != w[i].front()) {
      ok = false;
    }
    if (st.count(w[i])) {
      ok = false;
    }
    st.insert(w[i]);
  }
  if (ok) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  return 0;
}