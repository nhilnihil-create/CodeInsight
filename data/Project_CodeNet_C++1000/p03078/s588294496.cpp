#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e18;
using Graph = vector<vector<int>>;

signed main() {
  int X, Y, Z, K;
  cin >> X >> Y >> Z >> K;
  vector<int> A(X);
  vector<int> B(Y);
  vector<int> C(Z);
  for( int i = 0; i < X; i++ ) cin >> A[i];
  for( int i = 0; i < Y; i++ ) cin >> B[i];
  for( int i = 0; i < Z; i++ ) cin >> C[i];
  sort(A.rbegin(), A.rend());
  sort(B.rbegin(), B.rend());
  sort(C.rbegin(), C.rend());

  vector<int> kouho;
  for( int x = 0; x < X; x++ ){
    for( int y = 0; y < Y; y++ ){
      kouho.emplace_back(A[x]+B[y]);
    }
  }

  sort(kouho.rbegin(), kouho.rend());
  vector<int> ans;
  int ksize = (int)kouho.size();
  for( int i = 0; i < min(ksize, 3000LL); i++ ){
    for( int z = 0; z < Z; z++ ){
      ans.emplace_back(kouho[i]+C[z]);
    }
  }

  sort(ans.rbegin(), ans.rend());
  for( int i = 0; i < K; i++ ) cout << ans[i] << endl;

}
