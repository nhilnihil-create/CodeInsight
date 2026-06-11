#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int ma[1 << 18][2];

int main()
{
  int n;
  cin >> n;
  vector<int> a(1 << n);

  for (int i = 0; i < (1 << n); ++i) scanf("%d", &a[i]);

  for (int i = 0; i < (1 << n); ++i) ma[i][0] = a[i];  

  for (int i = 0; i < n; ++i) for (int mask = 0; mask < (1 << n); ++mask) {
    if (mask & (1 << i)) {
      int mask2 = mask ^ (1 << i);
      for (int t : ma[mask2]) {
        if (t > ma[mask][0]) {
          ma[mask][1] = ma[mask][0];
          ma[mask][0] = t;
        } else if (t > ma[mask][1]) {
          ma[mask][1] = t;
        }
      }
    }
  }          

  int result = 0;
  for (int k = 1; k < (1 << n); ++k) {
    result = max(result, ma[k][0] + ma[k][1]);
    cout << result << endl;
  }

  return 0;
}
