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
  ll N, A, B;
  cin >> N >> A >> B;
  vector<ll> P(N), a, b, c;
  for (int i = 0; i < N; i++) {
    cin >> P[i];
    if (P[i] <= A) {
      a.push_back(P[i]);
    } else if (A < P[i] && P[i] <= B) {
      b.push_back(P[i]);
    } else {
      c.push_back(P[i]);
    }
  }
  cout << min({a.size(), b.size(), c.size()}) << endl;
  return 0;
}