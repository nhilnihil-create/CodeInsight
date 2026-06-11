#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int H, W, h, w;

int main(){
  cin >> H >> W >> h >> w;
  cout << (H-h) * (W-w) << endl;
}
