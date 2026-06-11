#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;
const int INF = 1e15;
using Graph = vector<vector<int>>;

signed main(){
  int H, W;
  cin >> H >> W;
  vector<vector<int>> A(H, vector<int>(W));
  for( int i = 0; i < H; i++ ){
    for( int j = 0; j < W; j++ ) cin >> A[i][j];
  }

  vector<int> X;
  vector<int> Y;
  vector<int> NX;
  vector<int> NY;
  int ans = 0;
  for( int i = 0; i < H; i++ ){
    for( int j = 0; j < W-1; j++ ){
      if( A[i][j]%2 == 1 ){
        X.push_back(i+1);
        Y.push_back(j+1);
        NX.push_back(i+1);
        NY.push_back(j+2);
        ans++;
        A[i][j]--;
        A[i][j+1]++;
      }
    }
  }
  for( int i = 0; i < H-1; i++ ){
    if( A[i][W-1]%2 == 1 ){
      X.push_back(i+1);
      Y.push_back(W);
      NX.push_back(i+2);
      NY.push_back(W);
      ans++;
      A[i][W-1]--;
      A[i+1][W-1]++;
    }
  }

  cout << ans << endl;
  for( int i = 0; i < ans; i++ ){
    cout << X[i] << " " << Y[i] << " " << NX[i] << " " << NY[i] << endl;
  }
}
