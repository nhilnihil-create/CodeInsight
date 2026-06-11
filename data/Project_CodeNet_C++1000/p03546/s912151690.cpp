#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int h, w;
  cin >> h >> w;
  int mpt[10][10];
  for(int i=0; i<10; ++i) for(int j=0; j<10; ++j){
    cin >> mpt[i][j];
  }
  int t[10];
  for(int i=0; i<10; ++i) t[i] = mpt[i][1];
  mpt[1][1] = 0;
  for(int i=0; i<9; ++i){
    for(int j=0; j<10; ++j) for(int k=0; k<10; ++k){
      t[j] = min(t[j], mpt[j][k] + t[k]);
    }
  }
  
  int ans = 0;
  for(int i=0; i<h; ++i) for(int j=0; j<w; ++j){
    int x;
    cin >> x;
    if(x == -1) continue;
    ans += t[x];
  }
  cout << ans << endl;
}