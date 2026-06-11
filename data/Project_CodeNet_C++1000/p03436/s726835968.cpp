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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
  
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  rep(i,H) cin >> S[i];

  vector score(H, vector<int>(W, INF));
  score[0][0] = 1;

  queue<P> que;
  que.emplace(0, 0);
  while (!que.empty()) {
    P p = que.front(); que.pop();
    rep(i,4) {
      P q;
      q.first = p.first + dy[i];
      q.second = p.second + dx[i];
      if (q.first < 0 || q.first >= H || q.second < 0 || q.second >= W) continue;
      if (S[q.first][q.second] == '#' || score[q.first][q.second] < INF) continue;
      score[q.first][q.second] = score[p.first][p.second] + 1;
      que.push(q);
    }
  }

  if (score[H - 1][W - 1] == INF) cout << -1 << endl;
  else {
    int ans = H * W;
    ans -= score[H - 1][W - 1];
    rep(i,H) rep(j,W) if (S[i][j] == '#') ans--;
    cout << ans << endl;
  }

  return 0;
}