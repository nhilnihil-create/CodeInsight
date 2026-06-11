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
  cin >> N;
  long ans = 0;
  if (N % 10 == 2) ans++;
  if ((N % 100) / 10 == 2) ans++;
  if ((N % 1000) / 100 == 2) ans++;
  if ((N % 10000) / 1000 == 2) ans++;
  cout << ans << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(12);
  solve();
  return 0;
}
