#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  map<int, int> a;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    a[x]++;
  }
  int ans = 0;
  for (auto x : a) {
    if (x.second > x.first) ans += (x.second - x.first);
    else if (x.second < x.first) ans += x.second;
  }
  cout << ans << endl;
  return 0;
}
