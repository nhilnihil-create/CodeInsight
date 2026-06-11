#include <iostream>
using namespace std;
typedef long long ll;
  
int N;
int ans = 0;
  
// 3, 5, 7を組み合わせて作れる数値を全探索
void dfs(ll x, bool flag3, bool flag5, bool flag7) {
  if (x > N) return;
  // 3, 5, 7をすべて含むならansに+1
  if (flag3 && flag5 && flag7) ans++;
  
  dfs(10 * x + 3, true, flag5, flag7);
  dfs(10 * x + 5, flag3, true, flag7);
  dfs(10 * x + 7, flag3, flag5, true);
}
  
int main() {
  // 入力
  cin >> N;
  
  // 深さ優先探索
  dfs(0, 0, 0, 0);
  
  // 出力
  cout << ans << endl;
}