#include <bits/stdc++.h>
#define maxs 30005
using namespace std;

struct data {
  long long w, s, v;
};
bool operator<(const data &l, const data &r) {
  return l.s + l.w < r.s + r.w;
}

long long n;
vector<data> v;
long long dp[1005][31000] = {0};

long long solve();

int main() {
  cin >> n;
  v.resize(n);
  for(int i = 0; i < n; ++i)
    cin >> v[i].w >> v[i].s >> v[i].v;
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long ans = 0;
  sort(v.begin(), v.end());
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < maxs; ++j) {
      dp[i + 1][j] = dp[i][j];
      if(j >= v[i].w && j - v[i].w <= v[i].s)
        dp[i + 1][j] =
            max(dp[i + 1][j], dp[i][j - v[i].w] + v[i].v);
      ans = max(ans, dp[i + 1][j]);
    }
  return ans;
}