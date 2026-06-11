#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)  //  repマクロ
#define leng(n) (int)(log10(n)+1)  //  桁数
using namespace std;

signed main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  
  int sum = 0;
  rep(i, n) sum += a[i];
  
  int ans = 0;
  int minave = abs(sum - n * a[0]);
  rep(i, n-1) {
    if (minave > abs(sum - n * a[i+1])) {
      minave = abs(sum - n * a[i+1]);
      ans = i+1;
    }
  }
  cout << ans << endl;
}