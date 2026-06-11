#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const ll inf=1000000000007;

int main() {
  int H,W,h,w;
  cin >> H >> W >> h >> w;
  cout << H*W - h*W - H*w + h*w << endl;
  return 0;
}