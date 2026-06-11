#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
int n;
int a[110],b[110];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 1; i < n; i++) {
    a[i] += a[i-1];
  }
  for (int i = n - 2; i >= 0; i--) {
    b[i] += b[i+1];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, a[i] + b[i]);
  }
  cout << ans << endl;
}

/*　【提出前に確認すること】
・コンパイルできるか
・テストケース試したか
・オーバーフローあるか
*/