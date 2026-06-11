#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  int res = 0;

  auto dfs = [&](auto& f, int cur, int d)->void{
    if (d == n) {
      res += (cur % 2 == 0);
      return ;
    }
    for (int i = -1; i <= 1; i++) {
      f(f, cur * (a[d] + i), d + 1);
    }
  };

  dfs(dfs, 1, 0);
  cout << res << endl;
  return 0;
} 