#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
#define rep(i, n) for(int i = 0;i < (int)(n);i++)
int main() {
  const int dx[4]  = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
  int H, W, nh, nw, S = 0, c = 0;cin >> H >> W;
  P p;
  vector<string> v(H);
  queue<P> q, nq;
  rep(i, H) cin >> v[i];
  rep(i, H) rep(j, W) {
    if(v[i][j] == '#') q.push(P(i, j));
    else S++;
  }
  while(S > 0) {
    while(q.size() != 0) {
      p = q.front();q.pop();
      rep(i, 4) {
        nh = p.first + dx[i], nw = p.second + dy[i];
        if(0<=nh&&nh<H&&0<=nw&&nw<W&&v[nh][nw] == '.') {
          v[nh][nw] = '#';
          S--;
          nq.push(P(nh, nw));
        }
      }
    }
    swap(q, nq);
    c++;
  }
  cout << c << endl;
}