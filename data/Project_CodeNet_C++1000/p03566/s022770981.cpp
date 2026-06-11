#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
// const ll MOD = 1000000007;
// const int INF = 2000000000;

int N;
vector<int> t, v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  t.resize(N + 1);
  t[0] = 0;
  for (int i = 1; i <= N; i++) {
    int ti;
    cin >> ti;
    t[i] = t[i - 1] + ti * 2;
  }
  v.resize(N + 1);
  for (int i = 0; i < N; i++) {
    int vi;
    cin >> vi;
    v[i] = vi * 2;
  }
  v[N] = 0;

  double ans = 0;
  int t_idx = 0;
  int speed = 0;
  for (int time = 0; time < t[N]; time++) {
    if (time >= t[t_idx + 1]) {
      t_idx++;
    }

    int next_speed = speed < v[t_idx] ? speed + 1 : speed;
    for (int i = t_idx + 1; i <= N; i++) {
      int ti = t[i];
      int vi = v[i];
      if (speed - (ti - time - 1) > vi) {
        next_speed = min(next_speed, speed - 1);
      } else if (speed - (ti - time - 1) == vi) {
        next_speed = min(next_speed, speed);
      } else {
        next_speed = min(next_speed, speed + 1);
      }
    }

    ans += 0.5 * (speed + next_speed);
    speed = next_speed;
  }

  cout << fixed << setprecision(15) << ans / 4.0 << endl;
  return 0;
}