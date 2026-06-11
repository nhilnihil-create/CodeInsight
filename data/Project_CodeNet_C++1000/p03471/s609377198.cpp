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
  ll N, Y;
  cin >> N >> Y;
  Y /= 1000;
  int k;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; i + j <= N; j++) {
      k = N - i - j;
      if (N < i + j + k) continue;
      if (10 * i + 5 * j + k == Y) {
        cout << i << " " << j << " " << k << endl;
        return 0;
      }
    }
  }
  cout << -1 << " " << -1 << " " << -1 << endl;
  return 0;
}