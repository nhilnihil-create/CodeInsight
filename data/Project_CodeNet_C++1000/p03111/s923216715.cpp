#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int INF = 2e9;
int main() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  vector<int> len(n);
  rep(i,n) cin >> len[i];
  
  auto dfs = [&](auto& f, int x = 0, int y = 0, int z = 0, int i = 0)->int{
    if (i == n) {
      if (!x || !y || !z) return INF;
      return abs(a - x) + abs(b - y) + abs(z - c);
    }
    int res = f(f, x, y, z, i + 1);
    res = min(res, f(f, x + len[i], y, z, i + 1) + (x ? 10 : 0));
    res = min(res, f(f, x, y + len[i], z, i + 1) + (y ? 10 : 0));
    res = min(res, f(f, x, y, z + len[i], i + 1) + (z ? 10 : 0));
    return res;
  };

  cout << dfs(dfs) << endl;
  return 0;
} 