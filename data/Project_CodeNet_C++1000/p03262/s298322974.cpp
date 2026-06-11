#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, x;
  cin >> n >> x;
  vector<int> v(n + 1);
  rep(i, 0, n) cin >> v[i];
  v[n] = x;
  sort(v.begin(), v.end());

  vector<int> w(n);
  rep(i,1,n+1)
    w[i-1]=v[i]-v[i-1];
  
  int ggcd = w[0];
  rep(i, 0, n) { ggcd = __gcd(ggcd, w[i]); }

  cout << ggcd << endl;
}
