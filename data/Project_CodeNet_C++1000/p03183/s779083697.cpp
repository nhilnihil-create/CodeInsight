#include <bits/stdc++.h>
#define chmax(x, y) do { x = max(x, y);} while(0)
typedef long long int ll;

using namespace std;

ll N;
struct T{
  ll w, s, v;
};

vector<T> a;
ll dp[2000][30000]; // dp[i][j]: i番目のブロックまでみて、合計の重さがjのときの最大価値

int main() {
  cin >> N;
  for (int i=0; i<N; i++) {
    ll w, s, v;
    cin >> w >> s >> v;
    a.push_back({w,s,v});
  }
  sort(begin(a), end(a), [](const T &l, const T &r) {
      return min(l.s, r.s - l.w) > min(r.s, l.s - r.w);
      });
  dp[0][a[0].w] = a[0].v;
  dp[0][0] = 0;
  for (int i=0; i<N-1; i++) for (int j=0; j<30000; j++) {
    int ni = i+1;
    // niを置かない
    chmax(dp[ni][j], dp[i][j]);
    // niを置く
    int nj = j + a[ni].w;
    if (nj < 30000 && j <= a[ni].s) {
      chmax(dp[ni][nj], dp[i][j] + a[ni].v);
    }
  }
  ll ans = -1;
  for (int j=0; j<30000; j++) {
    chmax(ans, dp[N-1][j]);
  }
  cout << ans << endl;
  return 0;
}

