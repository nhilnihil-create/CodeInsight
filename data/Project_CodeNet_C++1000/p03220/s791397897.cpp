#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll N;
  long double T, A;
  cin >> N >> T >> A;
  vector<ll> H(N);
  vector<long double> C(N);
  int ans;
  long double min_res = 1000000.0;
  for (int i = 0; i < N; i++) {
    cin >> H[i];
    C[i] = T - 0.006 * H[i];
    if (abs(C[i] - A) < min_res) {
      min_res = abs(C[i] - A);
      ans = i + 1;
    }
  }
  cout << ans << endl;
  return 0;
}