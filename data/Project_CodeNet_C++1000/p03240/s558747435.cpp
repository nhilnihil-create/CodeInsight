#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  int x[N], y[N], h[N];

  for(int i = 0; i < N; i++) {
    cin >> x[i] >> y[i] >> h[i]; 
  }
  int si = -1;
  for(int i = 0; i < N; i++) {
    if(h[i] > 0) si = i;
  }
  
  int ansx, ansy, ansh;
  for(int X = 0; X <= 100; X++) {
    for(int Y = 0; Y <= 100; Y++) {
      bool ok = true;
      ll H = h[si] + abs(x[si] - X) + abs(y[si] - Y);
      for(int i = 0; i < N; i++) {
        if(h[i] > 0 && H - abs(x[i] - X) - abs(y[i] - Y) != h[i]) {
          ok = false;
        }
        if(h[i] == 0 && H > abs(x[i] - X) + abs(y[i] - Y)) {
          ok = false;
        }
  
      }
        if(ok) { ansx = X; ansy = Y; ansh = H; break; }
    }
  }
  cout << ansx << " " << ansy << " " << ansh;
    return 0;
}
