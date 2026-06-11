#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> x(N);
  for (int i = 0; i < N; i++) {
    int y;
    cin >> y;
    x[i] = abs(y - X);
  }

  int ans = x[0];
  for (int i = 1; i < N; i++) {
    ans = gcd(ans, x[i]);
  }
  cout << ans << endl;
  return 0;
}