#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> x(N);
  for (int i = 0; i < N; i++) cin >> x.at(i);
  x.push_back(X);
  int ans = 0;
  sort(x.begin(), x.end());
  for (int i = 0; i + 1 < x.size(); i++) {
    ans = __gcd(ans, x.at(i + 1) - x.at(i));
  }
  cout << ans << "\n";
}