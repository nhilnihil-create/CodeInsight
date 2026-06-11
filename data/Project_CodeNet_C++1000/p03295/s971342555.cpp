#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
struct pos {
  int row;
  int column;
};
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Sort(a) sort(a.begin(), a.end())
const int INF = 1 << 30;
const ll MOD = 1000000007;
int main(void) {
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> bridges;
  bridges.resize(M);
  rep(i, M) { cin >> bridges[i].second >> bridges[i].first; }

  Sort(bridges);

  int last = -1;
  int count = 0;
  rep(i, M) {
    if (last < 0 || bridges[i].second >= last) {
      last = bridges[i].first;
      count++;
    }
  }

  cout << count << endl;
  return 0;
}