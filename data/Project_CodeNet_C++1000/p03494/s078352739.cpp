#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, minCnt = 100000000;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, cnt = 0;
    cin >> a;
    while (a % 2 == 0) {
      a /= 2;
      cnt++;
    }
    if (minCnt > cnt) {
      minCnt = cnt;
    }
  }
  cout << minCnt << endl;
}
