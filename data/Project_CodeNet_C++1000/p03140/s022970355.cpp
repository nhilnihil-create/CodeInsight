#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int N;
  cin >> N;
  string A, B, C;
  cin >> A >> B >> C;
  
  vector<int> diff(N); //i文字目が何個違うか
  int ans = 0;
  for( int i = 0; i < N; i++ ){
    if( A.at(i) == B.at(i) && B.at(i) == C.at(i) ){
      diff.at(i) = 0;
      continue;
    }
    if( A.at(i) != B.at(i) ) diff.at(i)++;
    if( B.at(i) != C.at(i) ) diff.at(i)++;
    if( C.at(i) != A.at(i) ) diff.at(i)++;
  }
  
  for( int i = 0; i < N; i++ ){
    if( diff.at(i) > 0 ) ans += diff.at(i)-1;
  }
  cout << ans << endl;
    
    
  
}
