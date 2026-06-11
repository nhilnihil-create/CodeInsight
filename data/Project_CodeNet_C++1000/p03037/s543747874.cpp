#include <iostream>
#include <vector>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  int lmax = 0;
  int rmin = 1000000;
  rep(i, m){
    int l, r;
    cin >> l >> r;
    lmax = max(lmax, l);
    rmin = min(rmin, r);
  }
  int ans = max(0, rmin - lmax + 1);
  cout << ans << endl;
  
  return 0;
}