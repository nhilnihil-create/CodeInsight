#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
int main() {
  int n,y;
  cin >> n >> y;
  bool t = false;
  rep(i,n+1){
    int a = 0;
    rep(j,n-i+1){
      a = (i*10000) + (j*5000) + (n-i-j)*1000;
//      cout << a << ":" << ","<< i << "," << j<< "," <<n-i-j << endl;
      if (y == a) {
        t = true;
        cout << i << " " << j << " " << n-i-j << endl;
        j = n + 1;
        i = n + 1;
      }
    }
  }
  if (!t) cout << -1 << " " << -1 << " " << -1 << endl;
  return 0;
}
