#include <bits/stdc++.h>
using namespace std;

int f(int n) {
  if (n % 2 == 0) {
    return (n / 2);
  }
  else {
    return (3 * n + 1);
  }
}

int main() {
  int s;
  cin >> s;
  vector<int> a(1000005, 0);
  a.at(1) = s;
  set<int> st;
  st.insert(s);
  for (int i = 2; i < a.size(); i++) {
    a.at(i) = f(a.at(i - 1));
    if (st.count(a.at(i))) {
      cout << i << endl;
      break;
    }
    st.insert(a.at(i));
  }
  return 0;
}
