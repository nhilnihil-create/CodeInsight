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
  vector<ll> X(N), Y;
  for (int i = 0; i < N; i++) {
    cin >> X[i];
  }
  Y = X;
  sort(Y.begin(), Y.end());
  ll mid = Y[N / 2 - 1];
  ll mid_p = Y[N / 2];
  for (int i = 0; i < N; i++) {
    if (X[i] <= mid) {
      cout << mid_p << endl;
    } else {
      cout << mid << endl;
    }
  }
  return 0;
}