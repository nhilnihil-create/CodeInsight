#include <algorithm>
#include <climits>
#include <cmath>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using Graph = std::vector<std::vector<int>>;
using WGraph = std::vector<std::vector<std::pair<int, long long>>>;
using ll = long long;
using namespace std;
 
int main() {
  long long a = 0, b = 0, k = 0;
  cin >> a >> b >> k;
  int cnt = 0;
  while (cnt < k) {
    b += a/2;
    a /= 2;
    cnt++;
    if (cnt == k) break;
    a += b/2;
    b /= 2;
    cnt++;
  }
  cout << a << " " << b << endl;
  return 0;
}
