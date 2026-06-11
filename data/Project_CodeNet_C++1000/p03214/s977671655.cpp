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
  vector<ll> a(N);
  ll sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    sum += a[i];
  }
  ll min_diff = INF, min_id;
  for (int i = 0; i < N; i++) {
    if (abs(N * a[i] - sum) < min_diff) {
      min_diff = abs(N * a[i] - sum);
      min_id = i;
    }
  }
  cout << min_id << endl;
  return 0;
}