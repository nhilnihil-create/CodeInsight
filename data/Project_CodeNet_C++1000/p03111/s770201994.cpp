#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, s, n) for(int i = s; i < n; i++)
using namespace std;

int main(){
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  vector<int> l(n);
  rep(i, n) cin >> l[i];
  int m = pow(4, n);
  int ans = 1000000000;
  rep(i, m+1){
    int x = i;
    int la = 0, lb = 0, lc = 0;
    int cost = -30;
    rep(j, n){
      switch(x % 4){
        case 1:
          la += l[j];
          cost += 10;
          break;
        case 2:
          lb += l[j];
          cost += 10;
          break;
        case 3:
          lc += l[j];
          cost += 10;
          break;
      }
      x /= 4;
    }
    if (la == 0 || lb == 0 || lc == 0) continue;
    cost += abs(a-la) + abs(b-lb) + abs(c-lc);
    ans = min(ans, cost);
  }
  cout << ans << endl;
  
  return 0;
}