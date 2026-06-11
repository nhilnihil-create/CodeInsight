#include <bits/stdc++.h>
// #define int long long
using namespace std;

signed main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  
  int R = 0;
  int B = 0;
  for( int i = 0; i < N; i++ ){
    if( S.at(i) == 'R' ) R++;
    else B++;
  }
  if( R > B ) cout << "Yes" << endl;
  else cout << "No" << endl;
      
}


