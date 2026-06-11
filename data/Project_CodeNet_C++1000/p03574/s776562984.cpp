#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;


int get(const vvi &g, int H, int W, int h, int w)
{
  if (h < 0 || h >= H || w < 0 || w >= W)
    return 0;
  else
    return g[h][w];
}

int f(const vvi &g, int H, int W, int h, int w)
{
  int ans = 0;
  for (int i = -1; i <= 1; ++i)
    for (int j = -1; j <= 1; ++j)
      if (get(g, H, W, h+i, w+j) < 0)
        ++ans;
  return ans;
}

int main()
{
  int H, W;
  cin >> H >> W;
  vvi g(H, vi(W));
  for (int h = 0; h < H; ++h)
  {
    string s;
    cin >> s;
    for (int w = 0; w < W; ++w)
      g[h][w] = (s[w] == '.') ? 0 : -1;
  }

  for (int h = 0; h < H; ++h)
  {
    for (int w = 0; w < W; ++w)
    {
      if (g[h][w] < 0)
        cout << '#';
      else
        cout << f(g, H, W, h, w);
    }
    cout << endl;
  }  
}