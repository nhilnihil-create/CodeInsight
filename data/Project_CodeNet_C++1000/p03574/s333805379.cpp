#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll H, W;
  cin >> H >> W;
  vector<string> MAP(H);
  for (int i = 0; i < H; i++) {
    cin >> MAP[i];
  }
  vector<string> new_MAP(H);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (MAP[i][j] == '#') {
        cout << '#';
        continue;
      }
      ll cnt = 0;
      if (i - 1 >= 0 && MAP[i - 1][j] == '#') cnt++;
      if (j - 1 >= 0 && i - 1 >= 0 && MAP[i - 1][j - 1] == '#') cnt++;
      if (j + 1 < W && i - 1 >= 0 && MAP[i - 1][j + 1] == '#') cnt++;
      if (j - 1 >= 0 && MAP[i][j - 1] == '#') cnt++;
      if (j + 1 < W && MAP[i][j + 1] == '#') cnt++;
      if (i + 1 < H && MAP[i + 1][j] == '#') cnt++;
      if (i + 1 < H && j - 1 >= 0 && MAP[i + 1][j - 1] == '#') cnt++;
      if (i + 1 < H && j + 1 < W && MAP[i + 1][j + 1] == '#') cnt++;
      cout << cnt;
    }
    cout << endl;
  }
  return 0;
}