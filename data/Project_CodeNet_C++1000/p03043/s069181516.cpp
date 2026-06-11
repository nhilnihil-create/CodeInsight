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
  int N, K;
  cin >> N >> K;
  double ans = 0;
  for (int i = 1; i <= N; ++i) {
    int t = i;
    int re_ans = 1;
    while (t <= K-1) {
      t *= 2;
      re_ans *= 2;
    }
    ans += 1.0/(re_ans*N);
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}