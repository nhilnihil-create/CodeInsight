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
int ctoi(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return 0;
}
int64_t factorial(int64_t n) {
  if (n == 1) {
    return 1;
  }
  int64_t ans = factorial(n-1);
  return ans*n;
}
int64_t gcd(int64_t a, int64_t b) {
  if (a < b) {
    int64_t tmp = a;
    a = b;
    b = tmp;
  }
  int64_t r = a%b;
  while(r != 0) {
    a = b;
    b = r;
    r = a%b;
  }
  return b;
}

int main() {
  long long a, b, c, k;
  cin >> a >> b >> c >> k;
  if (k%2 == 0) {
    cout << a-b << endl;
  } else {
    cout << b-a << endl;
  }
}