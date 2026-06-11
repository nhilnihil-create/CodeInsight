#include <bits/stdc++.h>
using namespace std;

int main(){
  string str;
  cin >> str;
  bool chk = true;
  int index = 0;
  
  if(str.size() < 5){
    cout << "NO";
    return 0;
  }
  
  if(str.at(0) != 'A'){
    str = 'A' + str;
  }
  
  if(str.at(4) != 'A'){
    str = str.substr(0,4) + 'A' + str.substr(4);
  }
  
  if(str.at(6) != 'A'){
    str = str.substr(0,6) + 'A' + str.substr(6);
  }
  
  if(str.size() == 8){
    str = str + 'A';
  }

  if(str == "AKIHABARA") cout << "YES";
  else cout << "NO";
}
