#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int TN, TS;
  cin >> TN >> TS;
  vector<vector<int>> box(TS, vector<int>(2));
  for(int i = 0; i < TN; i++){
    cin >> box.at(i).at(0) >> box.at(i).at(1);
  }
  
  int ans = 1e9;
  for(int i = 0; i < (1 << TN); ++i){
    int sum = 0, num = 0, noNum = -1;
    for(int j = 0; j < TN; ++j){
      if(i >> j & 1){
        sum += box.at(j).at(0) * (j + 1) * 100 + box.at(j).at(1);
        num += box.at(j).at(0);
      }
      else {
        noNum = j;
      }
    }
    if(sum < TS){
      
      int Lscore = (noNum + 1) * 100;
      int lack = (TS - sum + Lscore -1) / Lscore;
      if(lack >= box.at(noNum).at(0)){
        continue;
      }
      else{
        num += lack;
      }
    }
    ans = min(ans, num);
  }
  cout << ans << endl;
}