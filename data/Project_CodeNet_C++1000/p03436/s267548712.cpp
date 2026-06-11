#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(), v.end()
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))

using ll = long long;
using PAIR = pair<int, int>;
using PAIRLL = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vll = vector<ll>;
using vvll = vector<vll>;

int main()
{
  int H, W,white=0;
  cin >> H >> W;
  vvc s(H, vc(W));
  rep(i,H)
  {
    rep(j,W)
    {
      cin >> s[i][j];
      if(s[i][j]=='.')
        white++;
    }
  }
  int inf = 100000000;
  vvi checked(H, vi(W, inf));
  int sx = 0, sy = 0, gx = H - 1, gy = W - 1;
  queue<PAIR> que;
  que.push(PAIR(sx, sy));
  checked[sx][sy] = 0;
  while(que.size())
  {
    PAIR p = que.front();
    que.pop();

    if(p.first==gx&&p.second==gy)
      break;

    int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};

    rep(i,4)
    {
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if(0<=nx&&nx<H&&0<=ny&&ny<W&&checked[nx][ny]==inf&&s[nx][ny]=='.')
        {
          checked[nx][ny] = checked[p.first][p.second] + 1;
          que.push(PAIR(nx, ny));
        }
    }
  }

  if(checked[gx][gy]==inf)
    cout << -1 << endl;
    else
    {
      cout << white - (checked[gx][gy] + 1) << endl;
    }

}
