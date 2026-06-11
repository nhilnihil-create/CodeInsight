#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

int main()
{
  int h, w, d;
  cin >> h >> w >> d;
  vector<P> val(h * w);
  rep(i, h) rep(j, w)
  {
    int a;
    cin >> a;
    a--;
    val[a] = P(i, j);
  }
  
  vector<int> dist(h * w, 0);
  rep(i, d)
  {
    for(int j = i + d; j < h * w; j += d)
    {
      int pj = j - d;
      dist[j] = dist[pj] + abs(val[j].first - val[pj].first) + abs(val[j].second - val[pj].second);
    }
  }
  
  //rep(i, h * w) cout << dist[i] << " ";
  
  int q;
  cin >> q;
  rep(i, q)
  {
    int l, r;
    cin >> l >> r;
    l--; r--;
    cout << dist[r] - dist[l] << "\n";
  }
  
  return 0;
}
  
  
  