#include <algorithm>
#include <iostream>
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
  int a, b;
  cin >> a >> b;
  a--, b--;
  int h = 100, w = 100;
  char ans[h][w];
  for (int i = 0; i < h / 2; ++i) {
    for (int j = 0; j < w; ++j) ans[i][j] = '.';
  }
  for (int i = h / 2; i < h; ++i) {
    for (int j = 0; j < w; ++j) ans[i][j] = '#';
  }
  for (int i = h / 2 + 1; i < h; i += 2) {
    for (int j = 0; j < w; j += 2) {
      if (a == 0) continue;
      ans[i][j] = '.';
      a--;
    }
  }
  for (int i = 0; i < h / 2; i += 2) {
    for (int j = 0; j < w; j += 2) {
      if (b == 0) continue;
      ans[i][j] = '#';
      b--;
    }
  }
  cout << h << " " << w << endl;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cout << ans[i][j];
    }
    cout << "\n";
  }
  return 0;
}