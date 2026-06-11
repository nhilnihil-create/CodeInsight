#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#define MOD (1000000007l)
#define rep(i, n) for(long i = 0; i < n; i++)

using namespace std;

void solve() {
  long N;
  string A, B, C;
  cin >> N >> A >> B >> C;

  long ans = 0;
  rep (i, N) {
    unordered_set<char> st;
    st.insert(A[i]);
    st.insert(B[i]);
    st.insert(C[i]);
    ans += st.size() - 1;
  }

  cout << ans << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(12);
  solve();
  return 0;
}
