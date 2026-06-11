#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt[35];
int n,m;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int a;
      cin >> a;
      cnt[a]++;
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    if (cnt[i] == n) {
      ans++;
    }
  }
  cout <<ans << endl;
}

/*　【提出前に確認すること】
・コンパイルできるか
・テストケース試したか
・オーバーフローあるか
*/
