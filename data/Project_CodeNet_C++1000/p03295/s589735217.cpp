#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int INF = 2e9;
int main() {
  int n, m;
  cin >> n >> m;
  vector<P> p;
  rep(i,m) {
    int a, b;
    cin >> a >> b;
    p.emplace_back(b, a);
  }

  sort(p.begin(), p.end());

  int res = 0;
  int prev = 0;
  for (int i = 0; i < m; i++) {
    if (p[i].second >= prev) {
      res++;
      prev = p[i].first;
    }
  }
  cout << res << endl;
  return 0;
} 