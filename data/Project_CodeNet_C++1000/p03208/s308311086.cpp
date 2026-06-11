#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> h(N);
  for (int i = 0; i < N; i++) {
    cin >> h.at(i);
  }
  sort(h.begin(), h.end());
  int ans = 1500000000;
  int k = 0;
  for (int i = K - 1; i < N; i++) {
    int memo = h.at(i) - h.at(k);
    ans = min(ans, memo);
    k++;
  }
  cout << ans << endl;
}