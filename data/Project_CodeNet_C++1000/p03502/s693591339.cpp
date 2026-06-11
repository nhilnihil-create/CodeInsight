#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  int s = 0, n = N;
  rep(i, 8) {
    s += n % 10;
    n /= 10;
    if (n == 0) {
      break;
    }
  }
  if (N % s == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}