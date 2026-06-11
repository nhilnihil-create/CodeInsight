#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const ll mod = 1000000000 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int N;
  cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
    v[i] -= i + 1;
  }
  sort(v.begin(), v.end());
  ll b = v[N / 2];
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ans += abs(v[i] - b);
  }
  cout << ans << endl;
}
