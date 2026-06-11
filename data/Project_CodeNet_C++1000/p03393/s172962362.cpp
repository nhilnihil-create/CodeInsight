#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  map<char,bool> mp;
  for(int i=0; i<S.size();i++){
    if(mp.count(S.at(i))){
      continue;
    }
    else{
      mp[S.at(i)] = true;
    }
  }
  
  if(S.size() <26){
    for(int i=0; i<26; i++){
      char x = 'a' + i;
      if(mp.count(x)){
        continue;
      }
      else{
        S += x;
        break;
      }
    }
    cout << S << endl;
  }
  else{
    int over = -1;
    for(int i=25; i>0; i--){
      if(S.at(i) > S.at(i-1)){
        over = i-1;
        break;
      }
    }
    if(over == -1){
      cout << over << endl;
    }
    else{
      for(int i=0; i<over; i++){
        cout << S.at(i);
      }
      for(int i=25; i>over; i--){
        if(S.at(i) > S.at(over)){
          cout << S.at(i);
          break;
        }
      }
    }
    cout << endl;
  }     
}