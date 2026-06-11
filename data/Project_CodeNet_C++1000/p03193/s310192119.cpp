#include<bits/stdc++.h>
using namespace std;
int main(){
  long long N, H, W;
  cin >> N >> H >> W;
  vector<vector<long long>> vec(N,vector<long long>(2));
  for(int i=0; i<N; i++){
    for(int j=0; j<2; j++){
      cin >> vec.at(i).at(j);
    }
  }
  
  int ans = 0;
  for(int k=0; k<N; k++){
    if((vec.at(k).at(0) >= H) && (vec.at(k).at(1) >= W)){
     ans++;
    }
  }
  cout << ans << endl;
}