#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e12;
using Graph = vector<vector<int>>;

signed main(){
  int N, A, B;
  cin >> N >> A >> B;
  vector<int> C(N);
  for( int i = 0; i < N; i++ ) cin >> C[i];

  if( N == 1 ){
    cout << abs(C[0]-B) << endl;
    return 0;
  }
  cout << max(abs(C[N-1]-B), abs(C[N-2]-C[N-1])) << endl;


}