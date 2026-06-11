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
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      ans = max(ans, abs(A[i] - A[j]));
    }
  }
  cout << ans << endl;
  return 0;
}