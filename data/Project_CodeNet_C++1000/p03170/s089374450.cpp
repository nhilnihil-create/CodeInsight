#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e12;
using Graph = vector<vector<int>>;

signed main(){
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for( int i = 0; i < N; i++ ) cin >> A[i];

  vector<bool> dp(K+10);
  for( int i = 1; i <= K; i++ ){
    for( int j = 0; j < N; j++ ){
      if( i-A[j] >= 0 && dp[i-A[j]] == 0 ) dp[i] = 1;
    }
  }
  if( dp[K] ) cout << "First" << endl;
  else cout << "Second" << endl;

}