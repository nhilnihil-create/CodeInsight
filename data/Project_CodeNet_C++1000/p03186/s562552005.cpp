#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll A,B,C;
  cin >> A >> B >> C;
  ll ans = B + min(A+B+1,C);
  cout << ans << endl;
  return 0;
}