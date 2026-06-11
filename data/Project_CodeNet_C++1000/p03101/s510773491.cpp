#include<bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int , int>;
  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int H, W, h, w; cin >> H >> W >> h >> w;

  cout << (H*W - (h*W + w*H) + h*w);
}
