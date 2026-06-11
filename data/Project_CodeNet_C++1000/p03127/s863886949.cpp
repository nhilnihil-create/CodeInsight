#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      int a;
      cin >> a;
      ans = a;
    } else {
      int a;
      cin >> a;
      ans = __gcd(ans,a);
    }
  }
  cout << ans << endl;
}

/*　【提出前に確認すること】
・コンパイルできるか
・テストケース試したか
・オーバーフローあるか
*/
