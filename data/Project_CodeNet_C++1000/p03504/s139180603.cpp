#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_TIME = 120000;
const int MAX_CHANNEL = 32;
int used[MAX_CHANNEL][MAX_TIME] = {};

int main() {
  int n, C;
  cin >> n >> C;

  for (int i = 0; i < n; i++) {
    int s, t, c;
    cin >> s >> t >> c;

    used[c][s - 1]++;
    used[c][t]--;

  }

  int ans = 0;
  for (int i = 1; i < MAX_TIME; i++) {
    int num = 0;
    for (int j = 0; j < MAX_CHANNEL; j++) {
      used[j][i] += used[j][i - 1];
      if (used[j][i]) num++;
    }
    ans = max(ans, num);
  }

  cout << ans << endl;

  return 0;
}