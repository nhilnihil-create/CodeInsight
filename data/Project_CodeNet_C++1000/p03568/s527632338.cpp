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
  ll exception = 1;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (A[i] % 2 == 0) exception *= 2;
  }
  ll ans = pow(3LL, N) - exception;
  cout << ans << endl;
  return 0;
}