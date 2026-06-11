#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int r, d, xi;
  cin >> r >> d >> xi;
  rep(i, 10) {
    xi = (r * xi) - d;
    cout << xi << endl;
  }
  return 0;
}