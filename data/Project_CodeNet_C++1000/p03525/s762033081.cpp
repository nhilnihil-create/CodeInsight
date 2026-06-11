#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  int N;
  cin >> N;
  vector<int> D(N);
  rep(i, N) cin >> D[i];
  sort(D.begin(), D.end());
  multiset<int> st{0};
  bool flag = true;
  rep(i, N) {
    if (flag)
      st.insert(D[i]);
    else
      st.insert((24-D[i])%24);
    flag ^= 1;
  }
  int ans = 1e9;
  for (auto i = st.begin(); i != st.end(); i++) {
    for (auto j = i; j != st.end(); j++) {
      if (i == j)
        continue;
      chmin(ans, min(*j-*i, 24+*i-*j));
    }
  }
  cout << ans << endl;
  return 0;
}