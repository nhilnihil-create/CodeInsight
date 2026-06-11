#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(int)(n); i++)


int main()
{
  int N;	cin >> N;
  int x[N], y[N], h[N];
  
  rep (i, N) {
    cin >> x[i] >> y[i] >> h[i];
  }
  int si = -1;
  rep(i, N) {
    if (h[i] > 0) si = i;
  }
  
  int Cx, Cy, Ch;
  rep(X,101) {
    rep(Y, 101) {
      bool ok = true;
      ll H = h[si] + abs(x[si] - X) + abs(y[si] - Y);
      rep(i, N) {
        if (h[i] > 0 && H - abs(x[i] - X) - abs(y[i] -Y) != h[i]) {
          ok = false;
        }
        if (h[i] == 0 && H > abs(x[i] - X) + abs(y[i] -Y)) {
          ok = false;
        }
      }
      if(ok) {
        Cx = X; Cy = Y; Ch = H;
        break;
      }
    }
  }
  cout << Cx << " " << Cy << " " << Ch << endl;
  return 0;
}