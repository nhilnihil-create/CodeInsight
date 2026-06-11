#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> h(N);
  for ( int i = 0; i < N; i++ ) {
    cin >> h[i];
  }

  sort(h.begin(), h.end());

  int ans = INF;
  for ( int i = 0; i < N-K+1; i++ ) {
    ans = min(ans, h[i+K-1]-h[i]);
  }

  cout << ans << endl;

  return 0;
}
