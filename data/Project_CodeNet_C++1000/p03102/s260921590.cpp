#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using ll = long long;
using GraphI = vector<vector<int>>;
using GraphC = vector<vector<char>>;
using pint = pair<int, int>;

const int INF = 1001001001;

int main() {
  int N, M, C;
  cin >> N >> M >> C;
  vector<int> B(M);
  rep(i, 0, M) cin >> B[i];

  int ans = 0;
  rep(i, 0, N) {
    int a = 0, tot = 0;
    rep(j, 0, M) {
      cin >> a;
      tot += a * B[j];
    }
    if (tot + C > 0) ans++;
  }

  cout << ans << endl;

  return 0;
}
