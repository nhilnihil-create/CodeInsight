#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll x;
ll a[300010];
int main() {
  cin >> n >> x;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a,a+n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (x >= a[i]) {
      x -= a[i];
      cnt++;
    }
  }
  if (cnt == n && x > 0) cnt--;
  cout << cnt << endl;
}

/*　【提出前に確認すること】
・コンパイルできるか
・テストケース試したか
・オーバーフローあるか
*/