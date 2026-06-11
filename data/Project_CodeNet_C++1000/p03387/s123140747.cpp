#include <bits/stdc++.h>
using namespace std;

int main() {

  vector<int> x(3);
  cin >> x[0] >> x[1] >> x[2];
  
  sort(x.begin(),x.end());
  
  int d1 = x[2] - x[0], d2 = x[2] - x[1],ans = 0;
  
  if ( d2 > 0 ){
    ans += d2;
    d1 -= d2;
  }
  
  if ( d1 % 2 == 0 ){
    ans += d1 /2;
  }else{
    ans += d1 / 2 + 2;
  }
  
  cout << ans << endl; 
  
}