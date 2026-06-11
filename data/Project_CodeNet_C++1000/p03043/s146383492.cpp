#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  double count = 0.0;
  rep(i, n){
    double x = (double)k / (i+1);
    int y = (int)log2(x);
    if (log2(x) <= 0.0) count += 1.0;
    else if (log2(x) == double(y)) count += 1.0 / pow(2, y);
    else count += 1.0 / pow(2, (y + 1));
  }
  double ans = count / n;
  cout << fixed << setprecision(12);
  cout << ans << endl;
  
  return 0;
}