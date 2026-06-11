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
int main(void) {
  int N, M;
  vector<P> dp;
  cin >> N >> M;
  rep(i, M) {
    int left, right;
    cin >> left >> right;
    dp.push_back(P(right, left));
  }

  Sort(dp);

  int count = 0;
  int before = 0;
  rep(i, M) {
    P p = dp[i];
    if (count == 0 || before <= p.second) {
      count++;
      before = p.first;
    }
  }

  cout << count << endl;

  return 0;
}