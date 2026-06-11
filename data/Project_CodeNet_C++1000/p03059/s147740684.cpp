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
  int A, B, T;
  cin >> A >> B >> T;
  int t = 0;
  int ans = 0;
  while (true) {
    t += A;
    if (t > T) break;
    else ans += B;
  }
  cout << ans << endl;
  return 0;
}