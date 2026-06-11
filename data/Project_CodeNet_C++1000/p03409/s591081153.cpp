#include <bits/stdc++.h>
#define int long long
using namespace std;
using Graph = vector<vector<int>>;

signed main(){
  int N;
  cin >> N;
  
  vector<pair<int, int>> R(N);
  for( int i = 0; i < N; i++ ){
    int X, Y;
    cin >> X >> Y;
    R.at(i) = make_pair(X, Y);
  }
  sort(R.rbegin(), R.rend());
  
  vector<pair<int, int>> B(N);
  for( int i = 0; i < N; i++ ){
    int X, Y;
    cin >> X >> Y;
    B.at(i) = make_pair(X, Y);
  }
  sort(B.begin(), B.end());
  
  int ans = 0;
  vector<bool> fg(N, true);
  for( int i = 0; i < N; i++ ){
    int Pkouho = -1;
    int PY = -1;
    for( int j = 0; j < N; j++ ){
      int RX = R.at(j).first;
      int RY = R.at(j).second;
      int BX = B.at(i).first;
      int BY = B.at(i).second;
      if( fg.at(j) && RX < BX && RY < BY ){
        if( PY < RY ){
          Pkouho = j;
          PY = RY;
        }
      }
    }
    if( Pkouho != -1 ){
      ans++;
      fg.at(Pkouho) = false;
      //cout << R.at(Pkouho).first << " " << B.at(i).first << endl;
    }
  }
  
  cout << ans << endl;
  
}
