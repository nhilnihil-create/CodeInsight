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
  priority_queue<pair<ll, ll>> q;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  ll min_life = A[0], min_ind = 0;
  set<ll> dead;
  while (dead.size() < N - 1) {
    for (int i = 0; i < N; i++) {
      if (i == min_ind || A[i] <= 0) continue;
      A[i] -= min_life * (A[i] / min_life);
      if (A[i] <= 0)
        dead.insert(i);
      else if (A[i] < min_life) {
        min_life = A[i];
        min_ind = i;
      }
    }
  }
  cout << min_life << endl;
  return 0;
}