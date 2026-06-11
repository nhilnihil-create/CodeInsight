#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  char s[5];
  scanf("%s", s);
  int a[4];
  rep(i, 4) a[i] = s[i] - '0';
  rep(bit, 1<<3) {
    int sm = a[0];
    rep(i, 3) {
      if (bit & 1<<i) sm += a[i + 1];
      else sm -= a[i + 1];
    }
    if (sm == 7) {
      char op[3];
      rep(i, 3) {
        if (bit & 1<<i) op[i] = '+';
        else op[i] = '-';
      }
      printf("%d%c%d%c%d%c%d=7\n", a[0], op[0], a[1], op[1], a[2], op[2], a[3]);
      return 0;
    }
  }
  return 0;
}