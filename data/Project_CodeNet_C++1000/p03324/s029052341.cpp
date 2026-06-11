#include <algorithm>
#include <cmath>
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
  int D, N;
  cin >> D >> N;

  if (D == 0) {
    if (N == 100)
      cout << 101 << endl;
    else
      cout << N << endl;
  } else if (D == 1) {
    if (N == 100)
      cout << 10100 << endl;
    else
      cout << N * 100 << endl;
  } else {
    if (N == 100)
      cout << 1010000 << endl;
    else
      cout << N * 10000 << endl;
  }

  return 0;
}
