#include <bits/stdc++.h>

using namespace std;

const int mx = 1 << 18;
vector<int> dp[mx];

vector<int> tmp;

void join(int x, int y) {
  tmp.clear();
  for (int it: dp[x]) tmp.push_back(it);
  for (int it: dp[y]) tmp.push_back(it);
  sort(tmp.rbegin(), tmp.rend());
  while (tmp.size() > 2) tmp.pop_back();
  dp[x] = tmp;
}

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  tmp.reserve(10);
  int n, x;
  cin >> n;
  const int N = 1 << n;

  for (int i = 0; i < N; ++i) {
    cin >> x;
    dp[i].push_back(x);
  }

  for (int i = 0; i < n; ++i) {
    for (int mask = 1; mask < N; ++mask) {
      if (mask >> i & 1) {
        join(mask, mask ^ (1 << i));
      }
    }
  }

  int premax = 0;
  for (int i = 1; i < N; ++i) {
    int sum = 0;
    for(int x: dp[i]) sum += x;
    if (premax < sum) {
      premax = sum;
    }
    cout << premax << '\n';
  }

  return 0;
}