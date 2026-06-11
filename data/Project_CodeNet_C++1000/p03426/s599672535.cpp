#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e16;

signed main(){
  
  cin.tie(0);
  ios::sync_with_stdio(false);

  int H, W, D;
  cin >> H >> W >> D;

  vector<vector<int>> A(H, vector<int>(W));
  vector<pair<int, int>> num(H*W+1);
  for( int i = 0; i < H; i++ ){
    for( int j = 0; j < W; j++ ){
      cin >> A.at(i).at(j);
      num.at(A.at(i).at(j)) = make_pair(i, j);
    }
  }
  
  vector<int> ruiseki(H*W+10, 0);
  for( int i = D+1; i <= H*W; i++ ){
    ruiseki.at(i) = ruiseki.at(i-D) + abs(num.at(i).first - num.at(i-D).first) +abs(num.at(i).second - num.at(i-D).second);
  }
  
  int Q;
  cin >> Q;

  for( int i = 0; i < Q; i++ ){
    int L, R;
    cin >> L >> R;
    int ans = ruiseki.at(R)-ruiseki.at(L);
    cout << ans << endl;
  }
  
}
