#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <numeric>
#include <time.h>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;
typedef long long ll;

#define rep(i, n) for (i = 0; i < n; i++)
#define P pair<int, int>

int main()
{
  int a, b;
  cin >> a >> b;

  int ans = 0;
  ans = max(ans, 2 * a - 1);
  ans = max(ans, 2 * b - 1);
  ans = max(ans, a + b);

  cout << ans << endl;
}
