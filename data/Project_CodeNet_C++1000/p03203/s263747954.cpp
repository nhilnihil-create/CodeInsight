#include <algorithm>
#include <bitset>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*----------------------------------------*/

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int h, w, n; cin >> h >> w >> n;
  vector<int> line(h, INF);
  REP(i, n) {
    int y, x; cin >> y >> x; --y; --x;
    line[y] = min(line[y], x);
  }
  int right = 1;
  FOR(i, 1, h) {
    if (line[i] < right) {
      cout << i << '\n';
      return 0;
    } else if (line[i] > right) {
      ++right;
    }
  }
  cout << h << '\n';
  return 0;
}
