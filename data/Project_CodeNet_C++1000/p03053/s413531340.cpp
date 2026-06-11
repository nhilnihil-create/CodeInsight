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
#define Sort(a) sort(a.begin(), a.end())
const int INF = 1 << 30;
const ll MOD = 1000000007;
vector<P> dirs = {
    P(0, 1),
    P(1, 0),
    P(0, -1),
    P(-1, 0),
};

int main(void) {
  int d[1002][1002];
  int ROW, COLUMN;
  cin >> ROW >> COLUMN;
  string grid[1002];
  queue<P> keep;

  rep(i, ROW) { cin >> grid[i]; }
  rep(i, ROW) {
    rep(j, COLUMN) { d[i][j] = -1000; }
    rep(j, COLUMN) {
      if (grid[i][j] == '#') {
        d[i][j] = 0;
        keep.push(P(i, j));
      }
    }
  }

  while (keep.size() > 0) {
    P cur = keep.front();
    int row = cur.first;
    int column = cur.second;
    keep.pop();
    for (P dir : dirs) {
      int nR = row + dir.first;
      int nC = column + dir.second;
      if (nR < 0 || nR >= ROW || nC < 0 || nC >= COLUMN ||
          grid[nR][nC] == '#' || d[nR][nC] != -1000)
        continue;
      d[nR][nC] = d[row][column] + 1;
      keep.push(P(nR, nC));
    }
  }

  int maxVal = -1 * INF;
  rep(row, ROW) {
    rep(column, COLUMN) { maxVal = max(maxVal, d[row][column]); }
  }

  cout << maxVal << endl;

  return 0;
}