#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e15;
using Graph = vector<vector<int>>;

signed main() {
  int N, X, Y;
  cin >> N >> X >> Y;
  vector<int> A(N);
  for( int i = 0; i < N; i++ ) cin >> A.at(i);

  if( N == 1 ){
    cout << abs(A.at(0)-Y) << endl;
    return 0;
  }

  int ans = max(abs(A[N-1]-A[N-2]), abs(A[N-1]-Y));
  cout << ans << endl;
}
