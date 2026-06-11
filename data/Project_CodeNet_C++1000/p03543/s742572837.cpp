#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  int d1, d2, d3, d4;
  d1 = n % 10;
  d2 = n / 10 % 10;
  d3 = n / 100 % 10;
  d4 = n / 1000;
  if (d2 == d3 && (d3 == d4 || d1 == d2)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}