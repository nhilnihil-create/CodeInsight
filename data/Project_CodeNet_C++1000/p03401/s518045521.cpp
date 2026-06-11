#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int n;
  cin >> n;
  vector<ll> a(n + 2);
  rep(i, n) {
    cin >> a[i + 1];
  }
  a[0] = a[n + 1] = 0;

  ll sum = 0;
  rep(i, n + 1) {
    sum += abs(a[i + 1] - a[i]); 
  }

  for (int i = 1; i <= n; ++i) {
    ll num = sum;
    num = num - abs(a[i - 1] - a[i]) - abs(a[i] - a[i + 1]);
    num = num + abs(a[i - 1] - a[i + 1]);
    cout << num << endl;
  }

  
  return 0;
}