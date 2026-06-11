#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  int k;
  string s;
  cin >> s >> k;
  priority_queue<string, vector<string>, greater<string>> v;
  unordered_set<string> st;
  int ss = s.size();
  for (int i = 0; i < ss; ++i) {
    for (int j = 1; i + j <= ss; ++j) {
      if (j > k) continue;
      string ss = s.substr(i, j);
      if (st.find(ss) == st.end()) {
        st.insert(ss);
        v.push(ss);
      }
    }
  }

  rep(i, k - 1) v.pop();
  cout << v.top() << endl;
  return 0;
}
