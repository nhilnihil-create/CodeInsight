#include<bits/stdc++.h>
using namespace std;

int main(){
  string str;
  char c;
  int cnt = 0;
  bool chk = true;
  
  cin >> str;
  
  if(str.substr(0,1) != "A") chk = false;
  
  for(int i = 2; i < str.size()-1; i++){
    c = str.at(i);
    if(str.substr(i,1) == "C") cnt++;
    else if(islower(c) == false) chk = false;
  }
  if(cnt != 1) chk = false;
  
  c = str.at(1);
  if(islower(c) == false) chk = false;
  c = str.at(str.size()-1);
  if(islower(c) == false) chk = false;
  
  if(chk == true) cout << "AC";
  else cout << "WA";
}