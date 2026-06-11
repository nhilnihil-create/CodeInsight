#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
#include <sstream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);

  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  sort(h.begin(), h.end());

  int ans = 1000000000;
  for (int i = 0; i <= n-k; i++) {
    ans = min(ans, h[i+k-1] - h[i]);
  }

  cout << ans << endl;
}