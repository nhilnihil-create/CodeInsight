#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  vector<int> A(4);
  for( int i = 0; i < 4; i++ ) cin >> A.at(i);
  if( count(A.begin(), A.end(), 1) == 1 && count(A.begin(), A.end(), 9) == 1 && count(A.begin(), A.end(), 7) == 1 && count(A.begin(), A.end(), 4) == 1 ){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }

}
