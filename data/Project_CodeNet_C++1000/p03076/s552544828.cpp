#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;

int time(int x) {
  return (x+9)/10 * 10;
}

int restime(int y) {
  return time(y) - y;
}

int main() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  
  int ans = time(a) + time(b) + time(c) + time(d) + time(e);
  ans -= max({restime(a) , restime(b) , restime(c) , restime(d) , restime(e)});
  cout << ans << endl;
}