#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <set>
#include <map>
#include <list>
#include <cstdlib>
#include <queue>
#include <stack>

using namespace std;

#define mod (1e9 + 7)
#define pi 3.1415926535897932
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, j, n) for(int i = j; i < n; i++)
#define repi(i, n) for (int i = 0; i <= n; i++)
#define repie(i, j, n) for (int i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl
#define P pair<int, int>
#define fi first
#define se second

typedef long long ll;

void solve1()
{
  int n, m; cin >> n >> m;
  vector<int> k(n);
  vector<vector<int>> a(n);
  rep(i, n) {
      cin >> k[i];
      for(int j = 0; j < k[i]; j++) {
          int in; cin >> in;
          a[i].push_back(in);
      }
  }

  int ans = 0;

  rep(i, m) {
      int cnt = 0;
      rep(j, n) {
          rep(m, k[j]) {
              if(a[j][m] == i+1) {
                  cnt ++;
              }
          }
      }

      if(cnt >= n) {
          ans ++;
      }
  }

  cout << ans << endl;
}



int main()
{
    solve1();
}