#include <iostream>
#include <set>
#include <vector>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  int n;
  string w[100] = {};
  set<string> st;

  cin >> n;
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    cin >> w[i];

    if (i == 0) {
      st.insert(w[i]);
      continue;
    }

    string p = w[i - 1];
    if (p[p.size() - 1] != w[i][0]) {
      ok = false;
      break;
    }

    set<string>::iterator it = st.find(w[i]);
    if (it != st.end()) {
      ok = false;
      break;
    }

    st.insert(w[i]);
  }
  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
