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
#define rep(i, n) for(long i = 0; i < (n); i++)

using namespace std;

void solve() {
  long N, K;
  cin >> N >> K;
  vector<long> a(N);
  rep (i, N) cin >> a[i];
  vector<long> acc(N+1, 0);
  rep (i, N) acc[i+1] = acc[i] + a[i];
  vector<long> beauty;
  for (long i = 0; i < acc.size(); i++)
    for (long j = i+1; j < acc.size(); j++)
      beauty.push_back(acc[j] - acc[i]);
  /*
  for (auto it: beauty) cout << it << " ";
  cout << endl;
  cout << "--------------=" << endl;
  */
  for (long i = 1l << 40; i > 0; i >>= 1) {
    vector<long> foo;
    for (auto it: beauty) if (it & i) foo.push_back(it);
    /*
    for (auto it: foo) cout << it << " ";
    cout << endl;
    */
    if (foo.size() >= K) beauty = foo;
  }
  long ans = beauty[0];
  for (auto it: beauty) ans &= it;
  cout << ans << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(12);
  solve();
  return 0;
}
