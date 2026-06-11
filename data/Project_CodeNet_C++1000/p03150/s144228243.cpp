#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  int index = 0;
  int tmpi;
  bool chk = true;
  cin >> str;
  
  vector<char> vec(7);
  vec.at(0) ='k';
  vec.at(1) ='e';
  vec.at(2) ='y';
  vec.at(3) ='e';
  vec.at(4) ='n';
  vec.at(5) ='c';
  vec.at(6) ='e';

  for(int i = 0; i < str.size(); i++){
    index = 0;
    tmpi = i;
    chk = true;
    for(int j = index; j < 7; j++){
      if(vec.at(j) == str.at(tmpi)){
        tmpi++;
        index = j;
      }else{
        chk = false;
        index = j;
        break;
      }
    }
    
    if(index == 6){
      cout << "YES";
      return 0;
    }
    
    string tmpStr = str.substr(tmpi, str.size() - tmpi);
    string chkStr = "";
    for(int j = index; j < 7; j++){
      chkStr += vec.at(j);
    }
    
    if(tmpStr.find(chkStr) == string::npos){
    }else{
      if(tmpStr.find(chkStr) + chkStr.size() + index == str.size()){
        cout << "YES";
        return 0;
      }else{
        cout << "NO";  
        return 0;
      }
    }
    cout << "NO";  
    return 0;
  }
     
}
