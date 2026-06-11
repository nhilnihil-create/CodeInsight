#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int gcd(int a, int b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

int gcds(vector<int> as) {
  int ans = as[0];
  for (int i = 1; i < as.size(); i++) {
    ans = gcd(ans, as[i]);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> as(n);
  rep(i, n) { cin >> as[i]; }
  cout << gcds(as) << endl;
  return 0;
}
