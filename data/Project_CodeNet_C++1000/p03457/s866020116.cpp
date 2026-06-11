#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
int main() {
  int n;
  cin >> n;
  bool ans = true;
  int t,x,y;
  int time = 0;
  int dx = 0;
  int dy = 0;
  rep(i,n){
    cin >> t >> x >> y;
    time = abs(time-t);
    dx = abs(dx - x);
    dy = abs(dy - y);
    if(time < (dx+dy)) ans = false;
    if(time %2 != (dx+dy) %2 ) ans = false;
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;

}
