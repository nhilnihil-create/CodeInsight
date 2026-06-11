#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int, int>;

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int divCnt(int num) {
  int cnt = 0;
  while (true) {
    if (num % 2 == 0) {
      cnt++;
      num /= 2;
    } else
      break;
  }
  return cnt;
}

int main() {
  int n;
  cin >> n;
  int result = 0;
  rep(i, n) {
    ll num;
    cin >> num;
    result += divCnt(num);
  }
  cout << result << endl;
  return 0;
}