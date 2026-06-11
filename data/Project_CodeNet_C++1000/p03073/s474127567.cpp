#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  int p=0;
  int q=0;
  for(int i = 0; i < S.size(); i++){ //0,1,0,1...
    if(i%2 == 0){
      if(S.at(i) == '1'){
        p++;
      }
    }
    if(i%2 == 1){
      if(S.at(i) == '0'){
        p++;
      }
    }
  }
  for(int i = 0; i < S.size(); i++){ //1,0,1,0...
    if(i%2 == 0){
      if(S.at(i) == '0'){
        q++;
      }
    }
    if(i%2 == 1){
      if(S.at(i) == '1'){
        q++;
      }
    }
  }
  cout << min(q,p) << endl;
}

