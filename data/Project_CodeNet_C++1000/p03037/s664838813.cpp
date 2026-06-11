#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>>LR(2, vector<int>(M));
  for(int i =0; i<M; i++){
    cin >> LR.at(0).at(i) >> LR.at(1).at(i);
  }
  
  int Lmax =0;
  int Rmin =1000000;
  
  for(int i=0; i<M; i++){
    if(Lmax<LR.at(0).at(i))Lmax=LR.at(0).at(i);
    if(Rmin>LR.at(1).at(i))Rmin=LR.at(1).at(i);
  }
  
  int ans=Rmin-Lmax+1;
  if(ans<0)ans=0;
  
  cout << ans << endl;
}