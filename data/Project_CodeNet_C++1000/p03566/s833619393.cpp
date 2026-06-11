#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define INF 1e9

double calcarea(int a, int b) {
  return (double)(a + b)/8.0;
}

int main() {
  int n;
  cin >> n;
  vector<int> t(n), v(n);

  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    sum += t[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  vector<int> limitSpeed(sum * 2 +1, INF);
  int now = 0;
  for (int i = 0; i < n; i++) {
    for (int j = now; j <= t[i]*2 + now; j++) {
      limitSpeed[j] = min(limitSpeed[j], v[i] * 2);
    }
    now += t[i] * 2;
  }

  limitSpeed[0] = 0;
  for (int i = 0; i < sum * 2; i++) {
    limitSpeed[i + 1] = min(limitSpeed[i + 1], limitSpeed[i] + 1);
  }
  limitSpeed[sum*2] = 0;
  for (int i = sum * 2; i >= 0; i--) {
    limitSpeed[i - 1] = min(limitSpeed[i - 1], limitSpeed[i] + 1);
  }

  double ans = 0.0;
  for (int i = 0; i < sum * 2; i++) {
    ans += calcarea(limitSpeed[i], limitSpeed[i + 1]);
  }
  cout << fixed << setprecision(12) << ans << endl;
  return 0;
}