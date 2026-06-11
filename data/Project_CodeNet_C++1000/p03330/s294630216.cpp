#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

int main(){
  int n, c;
  cin >> n >> c;
  int col[c][c];
  for(int i=0; i<c; ++i) for(int j=0; j<c; ++j) cin >> col[i][j];
  int cnn[n][n];
  for(int i=0; i<n; ++i) for(int j=0; j<n; ++j){
    cin >> cnn[i][j];
    --cnn[i][j];
  }
  vector<vector<int>> d(c, vector<int>(3,0));
  for(int i=0; i<c; ++i) for(int j=0; j<n; ++j) for(int k=0; k<n; ++k){
    if((j+k)%3 == 0) d[i][0] += col[cnn[j][k]][i];
    if((j+k)%3 == 1) d[i][1] += col[cnn[j][k]][i];
    if((j+k)%3 == 2) d[i][2] += col[cnn[j][k]][i];
  }
  
  int ans = INF;
  for(int i=0; i<c; ++i) for(int j=0; j<c; ++j){
    if(j == i) continue;
    for(int k=0; k<c; ++k){
      if(k == i || k == j) continue;
      int nans = d[i][0] + d[j][1] + d[k][2];
      ans = min(ans, nans);
    }
  }
  cout << ans << endl;
}