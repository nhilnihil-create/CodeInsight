#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MP(x, y) make_pair(x, y);
#define PB(v, x) v.push_back(x);
typedef pair<int, int> ii;

const int MAX = 18;

int N;
ii dp[(1 << MAX)+10];

ii add(ii a, ii b) {
  vector<int> v;
  PB(v,a.first);
  PB(v,a.second);
  PB(v,b.first);
  PB(v,b.second);
  sort(v.begin(), v.end());
  return MP(v[2], v[3]);
}

int result(ii p) {
  return p.first + p.second;
}

int main() {

  cin >> N;
  for (int i = 0; i < (1<<N); i++) {
    int x;
    cin >> x;
    dp[i] = MP(-1, x);
  }
  for (int j = 0; j < N; j++) {
    for (int i = (1<<N)-1; i >= 0; i--) {
      if (i & (1<<j))
        dp[i] = add(dp[i], dp[i&~(1<<j)]);
      else
        dp[i] = dp[i];
    }
  }
  int ans = 0;
  for (int i = 1; i < (1<<N); i++) {
    ans = max(ans, result(dp[i]));
    cout << ans << endl;
  }
}