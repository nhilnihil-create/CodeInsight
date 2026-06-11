#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  int H, W, h, w;
  cin >> H >> W >> h >> w;
  
  int ans = H*W;
  ans -= H*w + W*h;
  ans += w*h;
  
  cout << ans << endl;
  
  
  return 0;
}
