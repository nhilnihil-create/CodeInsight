#include <bits/stdc++.h>
using namespace std;

//type
#define ll long long
typedef pair<int, int> P;
//定数
#define INF 1000000000000 //10^12:∞
#define MOD 1000000007    //10^9+7:合同式の法
#define MAXR 100000       //10^5:配列の最大のrange
//略記
#define PB push_back //挿入
#define MP make_pair //pairのコンストラクタ
#define F first      //pairの一つ目の要素
#define S second     //pairの二つ目の要素
#define Z class
// OTHER
// xの二乗を返す (関数テンプレート版)
template <typename T>
T square(T x) { return x * x; }
#define chmax(x, y) (x = max(x, y))
#define chmin(x, y) (x = min(x, y))
// loop
#define REP(i, n) for (ll i = 0; i < ll(n); i++)
#define REPD(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= ll(b); i++)
#define FORD(i, a, b) for (ll i = a; i >= ll(b); i--)
#define FORA(i, I) for (const auto &i : I)

// vector
#define ALL(x) x.begin(), x.end()

// output
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n", (x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define ln cout << '\n'
template <Z A>
void pr(A a)
{
  cout << a;
  ln;
}
template <Z A, Z B>
void pr(A a, B b)
{
  cout << a << ' ';
  pr(b);
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

int main()
{
  int h, w;
  cin >> h >> w;

  vector<string> g(h);
  int black = 0;
  for (int i = 0; i < h; i++)
  {
    cin >> g[i];
    for (int j = 0; j < w; j++)
    {
      black += g[i][j] == '#';
    }
  }

  queue<pair<int, int>> q;
  q.emplace(0, 0);

  vector<vector<int>> dist(h, vector<int>(w, -1));
  dist[0][0] = 0;

  const int dy[] = {0, 1, 0, -1};
  const int dx[] = {1, 0, -1, 0};

  while (!q.empty())
  {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    for (int k = 0; k < 4; k++)
    {
      int yy = y + dy[k];
      int xx = x + dx[k];
      if (yy < 0 || xx < 0 || yy >= h || xx >= w)
        continue;
      if (g[yy][xx] == '#')
        continue;
      if (dist[yy][xx] != -1)
        continue;
      dist[yy][xx] = dist[y][x] + 1;
      q.emplace(yy, xx);
    }
  }

  if (dist[h - 1][w - 1] == -1)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << (h * w) - dist[h - 1][w - 1] - black - 1 << endl;
  }
}
