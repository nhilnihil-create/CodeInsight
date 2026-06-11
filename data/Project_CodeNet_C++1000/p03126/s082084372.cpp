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
  int N, M, K, a;
  cin >> N >> M;
  vector<int> v(M, 0);
  rep(i, 0, N) {
    cin >> K;
    rep(j, 0, K) {
      cin >> a;
      a--;
      v[a]++;
    }
  }

  int ans = 0;
  rep(i, 0, M) if (v[i] == N) ans++;
  cout << ans << endl;

  return 0;
}
