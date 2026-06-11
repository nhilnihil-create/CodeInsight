#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  scanf("%d", &n);
  int l = 0, r = n - 1, m;

  string sl, sr, sm;
  printf("%d\n", l);
  fflush(stdout);
  cin >> sl;
  printf("%d\n", r);
  fflush(stdout);
  cin >> sr;
  if (sl == "Vacant" || sr == "Vacant") return 0;

  while (l < r) {
    m = l + (r - l) / 2;
    printf("%d\n", m);
    fflush(stdout);
    cin >> sm;
    if (sm == "Vacant") return 0;
    if (((m - l) % 2 == 1 && sl != sm) || ((m - l) % 2 == 0 && sl == sm)) {
      l = m;
      sl = sm;
    } else {
      r = m;
      sr = sm;
    }
  }
  return 0;
}
