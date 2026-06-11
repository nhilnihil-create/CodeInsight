#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD =  1000000007;
const int INF = 1e11;
using Graph = vector<vector<int>>;

signed main(){
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<vector<int>> sum(N+1, vector<int>(N+1));
  for( int i = 0; i < M; i++ ){
    int L, R;
    cin >> L >> R;
    sum[L][R]++;
  }

  for( int i = 1; i <= N; i++ ){
    for( int j = 1; j <= N; j++ ){
      sum[i][j] = sum[i][j]+sum[i-1][j]+sum[i][j-1] - sum[i-1][j-1];
    }
  }

  for( int i = 0; i < Q; i++ ){
    int S, T;
    cin >> S >> T;
    cout << sum[T][T]-sum[T][S-1]-sum[S-1][T]+sum[S-1][S-1] << "\n";
  }

}
