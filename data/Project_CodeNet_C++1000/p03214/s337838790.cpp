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
  vector<long> a(N);
  rep(i, N) cin >> a[i];

  double avg;
  rep(i, N) avg += a[i];
  avg /= N;

  double foo = avg - a[0];
  if (foo < 0) foo *= -1;
  long bar = 0;

  rep (i, N) {
    double tmp = avg - a[i];
    if (tmp < 0) tmp *= -1;
    if (tmp < foo) {
      foo = tmp;
      bar = i;
    }
  }

  cout << bar << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(12);
  solve();
  return 0;
}
