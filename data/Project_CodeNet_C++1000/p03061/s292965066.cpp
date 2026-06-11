#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,ll> P;
typedef tuple<int,int,int> TP;
constexpr int INF = 2e9;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<int> left(n), right(n);
  left[0] = a[0];
  for (int i = 1; i < n; i++) left[i] = gcd(left[i - 1], a[i]);
  right[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) right[i] = gcd(right[i + 1], a[i]);
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) res = max(res, right[i + 1]);
    else if (i == n - 1) res = max(res, left[i - 1]);
    else res = max(res, gcd(right[i + 1], left[i - 1]));
  }
  cout << res << endl;
  return 0;
} 