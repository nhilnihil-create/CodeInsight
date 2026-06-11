#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  int k;
  string s;
  cin >> s >> k;
  set<string> st;
  int ss = s.size();
  for (int i = 0; i < ss; ++i) {
    for (int j = 1; i + j <= ss; ++j) {
      if (j > k) continue;
      string ss = s.substr(i, j);
      st.insert(ss);
    }
  }
  int cnt = 0;
  for (auto ans : st) {
   if (cnt != k - 1)
      cnt++;
    else {
      cout << ans << endl;
      return 0;
    }
  }
  return 0;
}
