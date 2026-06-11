#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int N, X;
  cin >> N >> X;
  vector<int> x(N);
  for (int i = 0; i < x.size(); i++) {
    cin >> x[i];
  }

  sort(x.begin(), x.end());

  int ans = abs(X - x[0]);

  for (int i = 1; i < x.size(); i++) {
    ans = __gcd(ans, abs(X - x[i]));
  }

  cout << ans << endl;
}