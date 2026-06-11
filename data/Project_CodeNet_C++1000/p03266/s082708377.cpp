#include <bits/stdc++.h>
#define int long long
using namespace std;
using Graph = vector<vector<int>>;
const int MOD = 1000000007;

signed main() {
  int N, K;
  cin >> N >> K;
  
  vector<int> amari(K+1, 0);
  for( int i = 1; i <= N; i++ ) amari.at(i%K)++;
  
  int ans = 0;
  for( int A = 0; A < K; A++ ){
    int B = (K-A)%K;
    if( 2*B % K != 0 ) continue;
    else{
      ans += amari.at(A)*amari.at(B)*amari.at(B);
    }
  }
  cout << ans << endl;
  
}