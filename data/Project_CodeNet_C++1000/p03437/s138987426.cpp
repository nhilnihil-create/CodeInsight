#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int X, Y;
  cin >> X >> Y;
  
  if( X % Y == 0 ){
    cout << -1 << endl;
    return 0;
  }else{
    for( int i = 2; i*X <= 1e+18; i++ ){
      if( (X*i) % Y != 0 ){
        cout << X*i << endl;
        return 0;
      }
    }
  }
    
}
