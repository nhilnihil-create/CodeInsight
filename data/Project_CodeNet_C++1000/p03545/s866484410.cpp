#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  int a = s[0] - '0', b = s[1] - '0', c = s[2] - '0', d = s[3] - '0';
  rep(i, 1<<3) {
    int e = a;
    char op1, op2, op3;
    if (i & 1<<2) {
      e += b;
      op1 = '+';
    } else {
      e -= b;
      op1 = '-';
    }
    if (i & 1<<1) {
      e += c;
      op2 = '+';
    } else {
      e -= c;
      op2 = '-';
    }
    if (i & 1<<0) {
      e += d;
      op3 = '+';
    } else {
      e -= d;
      op3 = '-';
    }
    if (e == 7) {
      printf("%d%c%d%c%d%c%d=7\n", a, op1, b, op2, c, op3, d);
      return 0;
    }
  }
  return 0;
}