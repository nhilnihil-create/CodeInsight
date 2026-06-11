#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)  //  repマクロ
#define leng(n) (int)(log10(n)+1)  //  桁数leng
#define INF 9223372036854775807 //  巨大数INF
using namespace std;

signed main() {
  int n, a, b;
  cin >> n >> a >> b;
  cout << min(a, b) << ' ' << max(0ll, -n+a+b) << endl;
}
