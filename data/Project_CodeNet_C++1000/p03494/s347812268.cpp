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
  cin >> N;
  vector<ll> A(N);
  bool zero_flag = false;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (A[i] % 2) zero_flag = true;
  }
  ll ans = 0;
  while (!zero_flag) {
    for (int i = 0; i < N; i++) {
      A[i] /= 2;
      if (A[i] % 2) zero_flag = true;
    }
    ans++;
  }
  cout << ans << endl;
  return 0;
}