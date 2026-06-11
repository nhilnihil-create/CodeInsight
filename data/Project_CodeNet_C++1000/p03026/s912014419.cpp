#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <climits>
#include <random>
#include <iomanip>

using namespace std;
using P = pair<long, long>;

typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define fillInt(xs, x)        \
  for (int i = 0; i < (x); i++) \
    scanf("%d", &xs[i]);
#define fillLong(xs, x)       \
  for (int i = 0; i < (x); i++) \
    scanf("%ld", &xs[i]);
#define fillString(xs, x)       \
  for (int i = 0; i < (x); i++) \
    cin >> xs[i];
#define sortv(xs) sort(xs.begin(), xs.end())
#define sortvinv(xs) sort(xs.begin(), xs.end(), std::greater<long>())
#define lbv(xs, x) lower_bound(xs.begin(), xs.end(), x) - xs.begin()
#define ubv(xs, x) upper_bound(xs.begin(), xs.end(), x) - xs.begin()
#define bs(xs, x) binary_search(xs.begin(), xs.end(), x)

#define rep(i,n) for(auto i=0; i<(n); i++)

const int mod = 1000000007;

int n;
vector<int> G[10005];
int c[10005];
int d[10005];
int idx;
map<int, int> ranks;

void dfs(int x) {
  if(d[x]) return;

  d[x] = c[idx++];

  rep(i, G[x].size()) {
    dfs(G[x][i]);
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;

  rep(i, n-1) {
    int a, b;
    cin >> a>>b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  rep(i, n) {
    cin >> c[i];
  }
  sort(c, c+n, greater<int>());

  dfs(0);
  long res = 0;
  rep(i, n-1) {
    res += c[n-i-1];
  }
  cout << res << endl;

  rep(i, n) {
    cout << d[i] << endl;
  }
}
