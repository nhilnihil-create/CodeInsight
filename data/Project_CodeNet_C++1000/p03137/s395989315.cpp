#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> X(M);
  for (int i = 0; i < M; i++)
  {
    cin >> X[i];
  }

  if (N >= M)
  {
    cout << 0 << endl;
    return 0;
  }
  
  sort(X.begin(), X.end());
  vector<int> dist(M - 1);
  for (int i = 0; i < M - 1; i++)
  {
    dist[i] = X[i + 1] - X[i];
    // cerr << dist[i] << endl;
  }
  sort(dist.rbegin(), dist.rend());

  
  int ans = X[M - 1] - X[0];
  // cerr << "ans=" << ans << endl;
  for (int i = 0; i < N - 1; i++)
  {
    // cerr << "dist[" << i << "]=" << dist[i] << endl;
    ans -= dist[i];
  }
  cout << ans << endl;

  return 0;
}