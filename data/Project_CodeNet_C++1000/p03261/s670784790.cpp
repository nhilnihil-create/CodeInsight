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
    string s = w[i - 1];
    string t = w[i];
    if (t.at(0) != s.at(s.size() - 1)) {
      ok = false;
    }
    if (st.count(t)) {
      ok = false;
    }
    st.insert(t);
  }
  if (ok) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  return 0;
}