#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int cost = 1e9;
  int N, T; cin >> N >> T;
  for (int i = 0; i < N; ++i) {
    int c, t; cin >> c >> t;
    if (t <= T) cost = min(cost, c);
  }
  if (cost == 1e9) cout << "TLE" << endl;
  else cout << cost << endl;
}
