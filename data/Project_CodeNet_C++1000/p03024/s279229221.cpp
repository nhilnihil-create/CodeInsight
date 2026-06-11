#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  string S;
  cin >> S;
  
  int n = (int)S.size();
  if( n <= 7 ){
    cout << "YES" << endl;
  }else{
    int win = 0;
    for( int i = 0; i < n; i++ ){
      if( S.at(i) == 'o' ) win++;
    }
    if( win + (15 - n) > 7 ){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
  
}