#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, num = 1;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int squareNum = num * 2;
    int kplus = num + k;
    if (squareNum < kplus) {
      num = squareNum;
    } else {
      num = kplus;
    }
  }
  cout << num << endl;
}
