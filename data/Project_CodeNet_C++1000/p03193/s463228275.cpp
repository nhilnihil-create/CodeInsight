#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, H, W, h, w, ans = 0;
  cin >> N >> H >> W;
  for (int i = 0; i < N; i++)
  {
    cin >> h >> w;
    if (h >= H && w >= W)
      ans++;
  }
  cout << ans << endl;
}