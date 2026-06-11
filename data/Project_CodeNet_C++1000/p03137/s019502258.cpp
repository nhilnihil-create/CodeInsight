#include <bits/stdc++.h>
#define REP(i, n) for (long i = 0; i < n; ++i)

using namespace std;

void solve(long N, long M, vector<long> X) {
  // if there's less number of targets than the pieces, we can win without any movement
  if (M <= N) {
    cout << 0 << endl;
    return;
  }

  // sort the targets
  sort(X.begin(), X.end());

  // calc the distances between targets
  vector<long> dist(M - 1);
  REP(i, M - 1)
    dist[i] = X[i + 1] - X[i];

  // sort the distances
  sort(dist.rbegin(), dist.rend());

  // if we have no extra piece, we should move the first piece from the begin to the end
  long ans(X.back() - X.front());

  // we can skip the N-1 longest gap by putting pieces in advance
  REP(i, N - 1)
    ans -= dist[i];

  cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  long N, M;
  cin >> N >> M;
  vector<long> X(M);
  REP(i, M)
    cin >> X[i];

  solve(N, M, move(X));

  return 0;
}
