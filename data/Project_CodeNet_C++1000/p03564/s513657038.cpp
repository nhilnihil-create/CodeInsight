// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

int main() {
  int n, k; cin >> n >> k;
  int x = 1;
  while (n--) {
    x = min(x * 2, x + k);
  }
  cout << x << endl;
  return 0;
}
