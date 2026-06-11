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
#include <cstring>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<ll> pow2;
  ll p = 1;
  while (p < (1LL<<62)/2) {
    p *= 2;
    pow2.push_back(p);
  }
  int n;
  cin >> n;
  multiset<int> st;
  rep(i, n) {
    int tmp;
    cin >> tmp;
    st.insert(tmp);
  }
  int ans = 0;
  while (st.size() >= 2) {
    auto tmp = st.end();
    tmp--;
    int mx = *tmp;
    st.erase(tmp);
    rep(i, pow2.size()) {
      int f = pow2[i]-mx;
      auto it = st.lower_bound(f);
      if (it != st.end() && *it == f) {
        st.erase(it);
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}