#include <bits/stdc++.h>
using namespace std;

int main() {
  int d, mark;
  cin >> d >> mark;
  map<int, pair<int, int>> quest;
  for (int i = 100; i <= d * 100; i += 100) {
    cin >> quest[i].first >> quest[i].second;
  }
  int ans = 1e5;
  for (int b = 0; b < (1 << d); b++) {
    bitset<10> s(b);
    int sum = 0;
    int total = 0;
    int max0 = 0;
    for (int i = 100; i <= d * 100; i += 100) {
      if (s.test(i / 100 - 1)) {
        sum += i * quest[i].first + quest[i].second;
        total += quest[i].first;
      } else
        max0 = max(max0, i);
    }
    // cout << sum << " " << total << " " << max0 << endl;
    if (mark <= sum)
      ans = min(ans, total);
    else if (sum < mark &&
             ((mark - sum + (mark - sum) % max0) / max0 < quest[max0].first)) {
      total += max((mark - sum + (mark - sum) % max0) / max0, 1);
      ans = min(ans, total);
    }
  }

  cout << ans << endl;
}
