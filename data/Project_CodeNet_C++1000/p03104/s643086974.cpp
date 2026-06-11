#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e15;
using Graph = vector<vector<int>>;

signed main() {
  int A, B;
  cin >> A >> B;

  int Astart = (A-1)/4;
  Astart *= 4;
  int C = Astart;
  for( int i = Astart+1; i < A; i++ ){
    C ^= i;
  }
  int Bstart = B/4;
  Bstart *= 4;
  int D = Bstart;
  for( int i = Bstart+1; i <= B; i++ ){
    D ^= i;
  }
  int ans = C^D;
  cout << ans << endl;
}
