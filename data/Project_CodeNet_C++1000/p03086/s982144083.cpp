#include<iostream>
#include<algorithm>
#include<vector>
#include <iomanip>
#include <cmath>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(){

  string S;
  
  cin >> S;
  
  int cnt =0;
  int answer = 0;
  for(int i=0; i<S.size(); i++){
    if(S.at(i) == 'A' || S.at(i) == 'C' || S.at(i) == 'T' || S.at(i) == 'G'){
      cnt++;
      answer = max(cnt, answer);
    }
    else{
      cnt = 0;
    }
  }
  
  cout << answer << endl;
  

  
  return 0;
  
}
