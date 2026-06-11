#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  int n, x;
  vi m(110);
  cin >> n >> x;
  int sum = 0;
  int min_m = 1001000100;
  rep(i, n) {
    cin >> m[i];
    sum += m[i];
    if (min_m > m[i]) min_m = m[i];
  }

  // 残り
  int leftovers = x - sum;
  int ans = n + leftovers / min_m;

  cout << ans << endl;


  return 0;
}