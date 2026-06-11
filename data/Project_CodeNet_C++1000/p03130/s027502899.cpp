#include <bits/stdc++.h>
// #define int long long
using namespace std;

signed main() {
  int A, B;
  vector<int> count(4);
  for( int i = 0; i < 3; i++ ){
    cin >> A >> B;
    count.at(A-1)++;
    count.at(B-1)++;
  }
  
  for( int i = 0; i < 4; i++ ){
    if( count.at(i) > 2 ){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
      
}

