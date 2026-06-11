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
  ll X, Y;
  cin >> X >> Y;
  ll start = X;
  int count = 0;
  while (start <= Y) {
    start = 2 * start;
    count++;
  }

  cout << count << endl;
  return 0;
}