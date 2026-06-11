#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a[3];
  rep(i, 3) cin >> a[i];
  sort(a, a + 3);
  int b = a[2] - a[0], c = a[2] - a[1];
  int ans = 0;
  if (b % 2 == 0 && c % 2 == 0) ans = b / 2 + c / 2;
  if (b % 2 == 0 && c % 2 == 1) ans = b / 2 + (c+1) / 2 + 1;
  if (b % 2 == 1 && c % 2 == 0) ans = (b+1) / 2 + c / 2 + 1;
  if (b % 2 == 1 && c % 2 == 1) ans = (b-1) / 2 + (c-1) / 2 + 1;
  cout << ans << endl;
  return 0;
}