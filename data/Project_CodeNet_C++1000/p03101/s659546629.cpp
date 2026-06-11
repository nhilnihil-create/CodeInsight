#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll MOD=1000000007;

int main() {
  int H,W,h,w;
  cin >> H >> W >> h >> w;
  H -=h;
  W -=w;
  cout << H*W << endl;
}