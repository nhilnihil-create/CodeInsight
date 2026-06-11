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
  ll N, D, X;
  cin >> N >> D >> X;
  vector<ll> A(N);
  ll sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    for (int j = 1; j <= D; j += A[i]) {
      sum++;
    }
  }
  ll ans = sum + X;
  cout << ans << endl;
  return 0;
}