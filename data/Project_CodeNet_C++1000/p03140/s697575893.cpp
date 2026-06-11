#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)  //  repマクロ
#define leng(n) (int)(log10(n)+1)  //  桁数leng
#define INF 9223372036854775807 //  巨大数INF
using namespace std;

signed main() {
  int n;
  cin >> n;
  string a, b, c;
  cin >> a >> b >> c;
  int ans = 0;
  rep(i, n) {
    set<char> kind;
    kind.insert(a.at(i));
    kind.insert(b.at(i));
    kind.insert(c.at(i));
    ans += kind.size() -1;
  }
  cout << ans << endl;
}
