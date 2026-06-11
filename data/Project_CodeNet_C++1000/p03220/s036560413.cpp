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
  int N, T, A; cin >> N >> T >> A;
  int ans = 0;
  double dif = 99999999.9;
  rep(i,N) {
    int h; cin >> h;
    if (abs(A - (T - h * 0.006)) < dif) {
      dif = abs(A - (T - h * 0.006));
      ans = i+1;
    }
  }
  cout << ans << endl;
  return 0;
}