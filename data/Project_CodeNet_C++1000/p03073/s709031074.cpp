#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int cntb = 0,cntw = 0;
  for(int i = 0; i < S.size(); i++){
    if(i % 2 == 0){
      if(S.at(i) == '1') cntb++;
    }
    if(i % 2 == 1){
      if(S.at(i) == '0') cntb++;
    }
  }
  for(int i = 0; i < S.size(); i++){
    if(i % 2 == 0){
      if(S.at(i) == '0') cntw++;
    }
    if(i % 2 == 1){
      if(S.at(i) == '1') cntw++;
    }
  }
  cout << min(cntb, cntw) << endl;
  return 0;
}