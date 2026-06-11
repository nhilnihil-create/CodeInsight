#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> X(M);
  rep(i,0,M-1) cin >> X[i];
  sort(X.begin(), X.end());

  vector<int> dist(M);
  dist[0] = 0;
  rep(i,1,M-1) dist[i] = abs(X[i] - X[i-1]);
  sort(dist.begin(), dist.end());

  int ans = 0;
  rep(i,0,M-N) ans += dist[i];
  cout << ans << endl;

  return 0;
}
