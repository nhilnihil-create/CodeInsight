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
using pint = pair<int, int>;

const int INF = 1001001001;

int main() {
  int N;
  string S;
  cin >> N >> S;

  int ans = 0;
  rep(i, 1, N) {
    int cnt = 0;
    for (char c = 'a'; c <= 'z'; c++) {
      bool left = false, right = false;
      rep(j, 0, i) if (S[j] == c) left = true;
      rep(j, i, N) if (S[j] == c) right = true;
      if (left && right) cnt++;
    }
    ans = max(ans, cnt);
  }

  cout << ans << endl;

  return 0;
}
