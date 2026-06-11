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
  ll N;
  cin >> N;
  int h, n, w;
  for (int i = 1; i <= 3500; i++) {
    for (int j = 1; j <= 3500; j++) {
      ll part = N * i * j;
      ll div = (4 * i * j - N * i - N * j);
      if (div > 0 && part % div == 0) {
        h = i, n = j;
        w = part / div;
        cout << h << " " << n << " " << w << endl;
        return 0;
      }
    }
  }
  return 0;
}