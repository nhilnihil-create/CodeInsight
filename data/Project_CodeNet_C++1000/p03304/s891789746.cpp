#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e15;
using Graph = vector<vector<int>>;

signed main() {

  cout << fixed << setprecision(16);

  double N, M, D;
  cin >> N >> M >> D;

  double ans;
  if( D == 0 ){
    ans = (M-1.0)/N;
    cout << ans << endl;
  }else{
    ans = 2.0*(N-D)/(N*N)*(M-1.0);
    cout << ans << endl;
  }
}