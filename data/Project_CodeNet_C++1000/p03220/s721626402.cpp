#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int N,T,A;
  cin >> N >> T >> A;
  
  vector<int> H(N);
  for(int i=0; i<N; i++){
    cin >> H.at(i);
  }
  
  double tem=0;
  double min=0;
  vector<vector<int>> ans(N, vector<int>(2));
  
  for(int i=0; i<N; i++){
    tem = (T * 1000 - H.at(i) * 6) - A * 1000;
    if(tem < 0){
      tem = -tem;
    }
    
    ans.at(i).at(0) = tem;
    ans.at(i).at(1) = i+1;
  }
  
  sort(ans.begin(),ans.end());
  cout << ans.at(0).at(1) << endl;
  
}