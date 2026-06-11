#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
#include<queue>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;
const int MOD = 1000000007;

#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef struct info {
  int x;
  int y;
  ll h;
} info;

int main()
{
  ll n;
  cin >> n;
  vector<info> a;
  rep(i,n) {
    info tmp;
    cin >> tmp.x >> tmp.y >> tmp.h;
    a.push_back(tmp);
  }

  sort(a.begin(), a.end(),
       [](const info& i, const info& j) { return i.h > j.h; });

  vector<vector<ll>> man(101, vector<ll>(101));
  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 100; j++) {
      man[i][j] = a[0].h + abs(a[0].x - i) + abs(a[0].y - j);
    }
  }

  vector<vector<bool>> check(101, vector<bool>(101, true));
  for (int u = 1; u < n; u++) {
    for (int i = 0; i <= 100; i++) {
      for (int j = 0; j <= 100; j++) {
        if (max(man[i][j] - abs(a[u].x - i) - abs(a[u].y - j), (ll)0) == a[u].h) continue;
        else {
          check[i][j] = false;
        }
      }
    }
  }

  rep(i,101) rep(j,101) {
    if (check[i][j] && man[i][j] > 0) printf("%d %d %lld\n", i, j, man[i][j]);
  }
}
