#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> c(n, 0), s(n, 0), f(n, 0);
  rep(i, n-1) cin >> c[i+1] >> s[i+1] >> f[i+1];

  vector<int> ans(n, 0);
  for(int i = 0; i < n; ++i){
    for(int j = i; j < n-1; ++j){
      ans[i] = max(ans[i], s[j+1]);
      ans[i] = (ans[i] + f[j+1] - 1) / f[j+1] * f[j+1];
      ans[i] += c[j+1];
    }
  }
  for(int i = 0; i < n; ++i){
    cout << ans[i] << endl;
  }
  return 0;
}
