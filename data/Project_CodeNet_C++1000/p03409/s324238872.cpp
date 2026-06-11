#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> P;
struct pos {
  int row;
  int column;
};
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Sort(a) sort(a.begin(), a.end(), greater<P>())
const int INF = 1 << 30;
const ll MOD = 1000000007;
int main(void) {
  int N;
  vector<P> reds;
  vector<P> blues;
  cin >> N;
  rep(i, N) {
    int x, y;
    cin >> x >> y;
    reds.push_back(P(x, y));
  }
  rep(i, N) {
    int x, y;
    cin >> x >> y;
    blues.push_back(P(x, y));
  }

  sort(reds.begin(), reds.end());
  sort(blues.begin(), blues.end());

  int count = 0;
  for (P blue : blues) {
    int index = -1;
    int maxVal = -1;

    for (int i = 0; i < reds.size(); i++) {
      P red = reds[i];
      if (red.first > blue.first) break;
      if (red.second > blue.second) continue;

      if (red.second >= maxVal) {
        maxVal = red.second;
        index = i;
      }
    }

    if (index == -1) continue;

    reds.erase(reds.begin() + index);
    count++;
  }

  cout << count << endl;

  return 0;
}