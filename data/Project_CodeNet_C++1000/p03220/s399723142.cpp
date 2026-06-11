#include <iostream>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n, t, a;
  cin >> n >> t >> a;
  int ans;
  double diff = 100000000.0;
  rep(i, n){
    int h;
    cin >> h;
    double d = abs((double)a - ((double)t-h*0.006));
    if ( d < diff ){
      diff = d;
      ans = i+1;
    }
  }
  cout << ans << endl;
  
  return 0;
}