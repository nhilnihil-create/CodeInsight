#include <bits/stdc++.h>
using namespace std;
typedef int64_t i64;

int main()
{
  int H,W,h,w;
  cin >> H >> W >> h >> w;

  int ans = (h*W) + (w*H);
  ans = ans - (h*w);
  ans = (H*W) - ans;

  cout << ans << endl;
}
