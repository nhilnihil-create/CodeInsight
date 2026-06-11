#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

int main() {
  
  int H, W, D, Q;
  cin >> H >> W >> D;
  vector A(H, vector<int>(W));
  vector<P> point(H * W + 1);
  rep(i,H) rep(j,W) {
    cin >> A[i][j];
    point[A[i][j]] = make_pair(i, j);
  }
  cin >> Q;
  vector<int> L(Q), R(Q);
  rep(i,Q) cin >> L[i] >> R[i];

  vector<ll> sum(H * W + 1, 0);
  rep(k,D) {
    int now = (D == 0 ? D : k);
    while (now + D <= H * W) {
      int next = now + D;
      sum[next] = sum[now];
      sum[next] += abs(point[now].first - point[next].first);
      sum[next] += abs(point[now].second - point[next].second);
      now = next;
    }
  }

  rep(i,Q) {
    cout << (sum[R[i]] - sum[L[i]]) << endl;
  }

  return 0;
}