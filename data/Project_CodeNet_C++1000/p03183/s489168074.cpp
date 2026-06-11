//Daniel Grzegorzewski
#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define MP make_pair
#define PB push_back
#define ST first
#define ND second
#define int long long

using namespace std;

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef long long LL;

void init_ios() {
     ios_base::sync_with_stdio(0);
     cin.tie(0);
}

const int N = (int)1e4 + 3;

int n, dp[N];
bool vis[N];
pair<PII, int> a[N];

bool cmp(pair<PII, int> x, pair<PII, int> y) {
  return x.ST.ND-y.ST.ST > y.ST.ND-x.ST.ST;
}

signed main() {
  init_ios();
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i].ST.ST >> a[i].ST.ND >> a[i].ND;
  sort(a+1, a+n+1, cmp);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j+a[i].ST.ST < N; ++j)
      if (vis[j+a[i].ST.ST]) {
        dp[min(j, a[i].ST.ND)] = max(dp[min(j, a[i].ST.ND)], a[i].ND+dp[j+a[i].ST.ST]);
        vis[min(j, a[i].ST.ND)] = true;
      }
    vis[a[i].ST.ND] = true;
    dp[a[i].ST.ND] = max(dp[a[i].ST.ND], a[i].ND);
  }
  int res = 0;
  for (int i = 0; i < N; ++i)
    res = max(res, dp[i]);
  cout<<res<<"\n";
}