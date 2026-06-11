#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  int n, k, q;
  cin >> n >> k >> q;
  int a[n];
  REP(i, n) cin >> a[i];
  int ans = 2000000000;
  for (int y : a) {
    vector<int> vec;
    multiset<int> st;
    REP(i, n + 1) {
      if (i == n || a[i] < y) {
        sort(ALL(vec));
        int len = vec.size();
        REP(j, len - k + 1) st.insert(vec[j]);
        vec.clear();
      } else {
        vec.push_back(a[i]);
      }
    }
    if (st.size() < q) continue;
    auto it = st.begin();
    REP(i, q - 1) it++;
    int x = *it;
    ans = min(ans, x - y);
  }
  cout << ans << endl;
  return 0;
}