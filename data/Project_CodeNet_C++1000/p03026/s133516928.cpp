#include <cstdio>
#include <climits>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <set>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
long long MOD = 1000000007;
long long INF = 1000000000000000; //10^15
typedef long long ll;
typedef unsigned long long ull;
int n;
vector<int> g[10010];
int a[10010], b[10010], c[10010];


int main(void) {

  cin >> n;
  rep(i, n - 1) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }
  rep(i, n) cin >> c[i];
  sort(c, c + n);
  int f[10010];
  rep(i, n) f[i] = g[i].size();
  

  set< pair<int, int> > s;
  rep(i, n) s.insert(make_pair(f[i], i));

  int d[10010], cnt = 0;
  while (!s.empty()) {
    int j = (s.begin())->second;
    d[j] = c[cnt++];
    s.erase(make_pair(f[j]--, j));
    rep(i, g[j].size()) {
      s.erase(make_pair(f[g[j][i]], g[j][i]));
      if (f[g[j][i]] != 0) {
	s.insert(make_pair(--f[g[j][i]], g[j][i]));
      }
    }
  }
  int ans = 0;
  rep(i, n - 1) ans += min(d[a[i]], d[b[i]]);
  cout << ans << endl;
  rep(i, n - 1) cout << d[i] << " ";
  cout << d[n - 1] << endl;

  return 0;
}

  

    
