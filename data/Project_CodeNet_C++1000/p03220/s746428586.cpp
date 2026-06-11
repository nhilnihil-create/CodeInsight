#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, t, a;
  cin >> n >> t >> a;
  vector<int> h(n);
  rep(i, n) cin >> h[i];

  int m = 1000000000;
  int j = 1;
  rep(i, n) {
    int tmp;
    tmp = 1000*t - h[i]*6;
    if (m > abs(tmp - a * 1000)) {
      m = abs(tmp - a * 1000);
      j = i + 1;
    }
  }
  
  cout << j << endl;
  return 0;
}