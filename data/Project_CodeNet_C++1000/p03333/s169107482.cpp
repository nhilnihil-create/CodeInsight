#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long sol, tmp;

int st[100001], dr[100001];

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> st[i] >> dr[i];
    st[i] *= 2;
    dr[i] *= -2;
  }
  sort(st + 1, st + n + 1);
  sort(dr + 1, dr + n + 1);
  reverse(st + 1, st + n + 1);
  reverse(dr + 1, dr + n + 1);
  for(int i = 1; i <= n; i++) {
    sol = max(sol, tmp + st[i]);
    sol = max(sol, tmp + dr[i]);
    sol = max(sol, tmp + st[i] + dr[i]);
    tmp += st[i] + dr[i];
  }
  cout << sol;
  return 0;
}
