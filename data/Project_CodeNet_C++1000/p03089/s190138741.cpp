#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> b(n);
  rep(i, n) cin >> b[i];

  vector<int> order(n, -1);
  set<int> st;
  rep(i, n) {
    for (int j = n-1; j >= 0; --j) {
      if (st.find(j) != st.end()) continue;
      int cl = 0;
      for (auto itr = st.begin(); itr != st.end(); ++itr) {
        if (*itr < j) ++cl;
      }
      if (cl == b[j] - 1) {
        order[i] = b[j];
        st.insert(j);
      }
      if (order[i] != -1) break;
    }
    if (order[i] == -1) {
      cout << -1 << endl;
      return 0;
    }
  }
  rep(i, n) cout << order[i] << endl;
  return 0;
}