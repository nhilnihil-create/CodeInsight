#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int r, d, x;
  cin >> r >> d >> x;
  for (int i = 1; i <= 10; ++i) {
    x = r * x - d;
    cout << x << endl;
  }
  return 0;
}