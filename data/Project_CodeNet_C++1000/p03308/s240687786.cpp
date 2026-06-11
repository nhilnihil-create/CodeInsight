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
  int n;
  cin >> n;
  vector<int> a(n);
  int m = 1000000000, M = 0;
  rep(i, n) {
    cin >> a[i];
    m = min(m, a[i]);
    M = max(M, a[i]);
  }

  cout << M - m << endl;
  return 0;
}