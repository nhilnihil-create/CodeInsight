#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
using namespace std;
typedef long long int lld;
typedef pair<int, int> pii;



int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector <pii> E;
  for (int i = 1; i <= n; i++) {
    int match = n-i + (n&1 ? 0 : 1);
    for (int j = i+1; j <= n; ++j) {
      if (j == match) continue;
      E.push_back({i, j});
    }
  }
  cout << E.size() << "\n";
  for (auto e : E) {
    cout << e.first << " " << e.second << "\n";
  }
  return 0;
}