#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int dx = x2 - x1;
  int dy = y2 - y1;
  dy *= -1;
  swap(dx, dy);
  int x3 = dx + x2, y3 = dy + y2;
  dy *= -1;
  swap(dx, dy);
  int x4 = dx + x3, y4 = dy + y3;
  cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
  return 0;
}