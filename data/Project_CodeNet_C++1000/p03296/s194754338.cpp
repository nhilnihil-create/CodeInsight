#include <bits/stdc++.h>

using namespace std;

#define range(i, m, n) for(int i = m; i < n; i++)
#define husk(i, m, n) for(int i = m; i > n; i--)

int n;

int main() {
  cin >> n;
  int res = 0;
  int cur = -1;
  int l = 0;
  range(i, 0, n) {
    int a;
    cin >> a;
    if(a != cur) {
      res += (i - l) / 2;
      cur = a;
      l = i;
    }
  }
  res += (n - l) / 2;
  cout << res;
  return 0;
}
