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
  ll N, M, X;
  cin >> N >> M >> X;
  vector<bool> A(N, false);
  ll a;
  for (int i = 0; i < M; i++) {
    cin >> a;
    A[a] = true;
  }
  ll i = X;
  ll ans1 = 0;
  while (i > 0) {
    i--;
    if (A[i]) ans1++;
  }
  i = X;
  ll ans2 = 0;
  while (i < N) {
    i++;
    if (A[i]) ans2++;
  }
  cout << min(ans1, ans2) << endl;
  return 0;
}