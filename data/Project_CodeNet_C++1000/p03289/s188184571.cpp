#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int count = 0;
  bool flag1 = false, flag2 = false;
  if(s[0] == 'A') flag1 = true;
  for(int i = 2; i < s.size()-1; i++){
    if(s[i] == 'C') flag2 = true;
  }
  if(flag1 == false || flag2 == false){
    cout << "WA" << endl;
    return 0;
  }
  for(int i = 1; i < s.size(); i++){
    if(s[i] == 'C') count++;
    if(s[i] != 'C'){
      if(s[i] <= 'Z'){
      cout << "WA" << endl;
      return 0;
      }
    }
  }
  if(count != 1){
    cout << "WA" << endl;
    return 0;
  }else{
    cout << "AC" << endl;
    return 0;
  }
}