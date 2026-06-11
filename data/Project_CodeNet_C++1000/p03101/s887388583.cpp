#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int H, W, h, w;
  cin >> H >> W >> h >> w;
  int ans = (H-h)*(W-w);
  cout << ans << endl;

  return 0;
}