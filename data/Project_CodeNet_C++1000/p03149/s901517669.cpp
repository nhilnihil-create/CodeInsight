#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
int64_t abs(int64_t n) {
  if (n < 0) {
    n = -n;
  }
  return n;
}
int ctoi(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return 0;
}

int main() {
  int a = 0, b = 0, c = 0, d = 0;
  rep(i, 4) {
    int n;
    cin >> n;
    if (n == 1) {
      a++;
    } else if (n == 9) {
      b++;
    } else if (n == 7) {
      c++;
    } else if (n == 4) {
      d++;
    }
  }
  if ((a==1) && (b==1) && (c==1) && (d==1)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}