#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  set<string> st;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    st.insert(s);
  }

  int cnt = st.size();
  if (cnt == 3) {
    puts("Three");
  } else {
    puts("Four");
  }

  return 0;
}
