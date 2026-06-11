#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

int main(){
  string S;
  cin >> S;
  vector<vector<int>> DP(2,vector<int>(S.size(),0));
  if(S.at(0)=='0') DP.at(1).at(0)=1;
  else DP.at(0).at(0)=1;

  for(int i=1;i<S.size();i++){
    if(S.at(i)=='0'){
      DP.at(0).at(i)=DP.at(1).at(i-1);
      DP.at(1).at(i)=DP.at(0).at(i-1)+1;
    }
    else{
      DP.at(0).at(i)=DP.at(1).at(i-1)+1;
      DP.at(1).at(i)=DP.at(0).at(i-1);
    }
  }

  cout << min(DP.at(0).at(S.size()-1),DP.at(1).at(S.size()-1)) << endl;
  
  return 0;
}
