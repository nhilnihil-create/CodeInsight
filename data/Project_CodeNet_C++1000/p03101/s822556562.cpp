#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>
#include <deque>
#include <set>
#include <stack>
 
using namespace std;
 
typedef long long ll;
const ll nmax = 1e9 + 7;
const ll mod = 998244353;
const double PI = 2 * asin(1);

int main() {
  int H, W;
  cin >> H >> W;
  int h, w;
  cin >> h >> w;
  
  int ans = H * W - h * W - H * w + h * w;
  cout << ans << endl;
  return 0;
}