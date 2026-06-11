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

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if ((b-a)%2 == 0) {
    cout << "Alice" << endl;
  } else {
    cout << "Borys" << endl;
  }
}