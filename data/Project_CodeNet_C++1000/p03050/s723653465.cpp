#include <bits/stdc++.h>
#define int long long
using namespace std;
using Graph = vector<vector<int>>;


signed main(){
  
  int N;
  cin >> N;
  
  int ans = 0;
  for( int i = 1; i <= sqrt(N); i++ ){
    if( N%i == 0 ){
      int A = N/i-1;
      if( A == 0 ) continue;
      int B = N/A;
      if( B == N%A ) ans += A;
      if( i == 1 || i == N/i ) continue;
      A = i-1;
      B = N/A;
      if( B == N%A ) ans += A;
    }
  }
  cout << ans << endl;
}
