#include <bits/stdc++.h>
using namespace std;

int main() {
  long long num;
  string str;
  cin >> num;
  int one = 0;
  int kurisage = 0;
  int other = 0;
  
  str = to_string(num);
  int len = str.size();
  
  if(len == 1){
    cout << num;
  }else{
    int cnt = 0;
    for(int i = 0; i < len; i++){
      if(str.at(i) == '9') cnt++;
      else break;
    }
    
    bool chk2 = true;
    for(int i = 1; i < len; i++){
      if(str.at(i) != '9') chk2 = false;
    }
    
    if(cnt == 0){
      if(chk2 == true){
        // 199999
        one = stoi(str.substr(0,1));
        other = (len - 1) * 9;
        cout << one + other; 
      }else{
        // 11111
        one = stoi(str.substr(0,1)) - 1;
        other = (len - 1) * 9;
        cout << one + other; 
      }
    }else if(cnt == 1){
      // 911111
      one = stoi(str.substr(0,1)) - 1;
      cout << one + ((len - 1) * 9);
    }else if(cnt == len){
      cout << len * 9;
    }else{
      // 991111
      one = (cnt - 1) * 9;
      kurisage = 8;
      other = (len - cnt) * 9;
      cout << one + kurisage + other; 
    }
  }
  
}
