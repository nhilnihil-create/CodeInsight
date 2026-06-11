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
  vector<ll> a(N), b(N);
  ll sum_a = 0, sum_b = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> b[i];
  }
  ll cnt_b = 0, cnt_a = 0;
  for (int i = 0; i < N; i++) {
    if (a[i] > b[i]) {
      cnt_b += a[i] - b[i];
    } else if (a[i] < b[i]) {
      cnt_a += (b[i] - a[i]) / 2;
    }
  }
  if (cnt_a < cnt_b) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
}