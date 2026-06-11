#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  int oldt = 0, oldx = 0, oldy = 0;
  bool can = true;
  int t, x, y;
  rep(i,n) {
    cin >> t >> x >> y;
    int dt = t - oldt;
    int dx = x-oldx;
    int dy = y-oldy;
    
    if (dt < abs(dx)+abs(dy) || dt%2 != (abs(dx)+abs(dy))%2) {
      can = false;
      break;
    }
    
      oldx = x;
      oldy = y;
      oldt = t;
  }
  
  if(can) cout << "Yes" << endl;
  else cout << "No" << endl;
}