#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

void solve(ll H, ll W, ll h, ll w) {
  cout << (H-h)*(W-w) << endl;
}

int main() {
  ll H;
  cin >> H;
  ll W;
  cin >> W;
  ll h;
  cin >> h;
  ll w;
  cin >> w;
  solve(H, W, h, w);
  return 0;
}
