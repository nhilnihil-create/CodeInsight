#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> a(n+1);
  rep(i, m) {
    int at;
    cin >> at;
    a[at] = 1;
  }
  int left = 0;
  int right = 0;
  for(int i = 0; i < x; i++) {
    left += a[i];
  }
  for(int i = x; i < n+1; i++) {
    right += a[i];
  }
  int ans = min(left, right);
  cout << ans << endl;
  return 0;
} 