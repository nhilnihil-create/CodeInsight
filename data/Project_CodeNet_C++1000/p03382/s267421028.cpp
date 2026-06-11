#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int N;
  cin >> N;
  
  vector<int> A(N);
  for( int i = 0; i < N; i++ ){
    cin >> A.at(i);
  }
  sort( A.begin(), A.end() );
  
  int L = A.at(N-1);
  int R;
  int sa = 1000000000000;
  for( int i = 0; i < N-1; i++ ){
    if( abs( A.at(i) - L/2 ) <= sa ){
      R = A.at(i);
      sa = abs( A.at(i) - L/2 );
    }
  }
  cout << L << " " << R << endl;
    
  
  
}