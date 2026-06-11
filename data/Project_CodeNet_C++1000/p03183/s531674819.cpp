#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Block {
  int w, s, v;
};
bool operator<(Block a, Block b) {
  return a.s+a.w < b.s+b.w;
}

Block a[1000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i].w >> a[i].s >> a[i].v;
  sort(a, a+n);
  int maxs = 1e4+1;
  vector<ll> dp(maxs,0);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    vector<ll> ndp = dp;
    for (int j = 0; j <= a[i].s; j++) {
      ll score = dp[j]+a[i].v;
      ans = max(ans, score);
      if (j+a[i].w < maxs)
	ndp[j+a[i].w] = max(ndp[j+a[i].w], score);
    }
    swap(dp, ndp);
  }
  cout << ans << endl;
}
