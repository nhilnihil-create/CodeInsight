#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = n; i <= 999; i++) {
    string str = to_string(i);
    set<char> st;
    for (int i = 0; i < str.size(); i++) {
      st.insert(str[i]);
    }
    if (st.size() == 1) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}