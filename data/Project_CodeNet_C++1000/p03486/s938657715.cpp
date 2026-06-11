#include <bits/stdc++.h>
using namespace std;

int main() {
  string str1, str2;
  bool chk = false;
  int index = 0;
  
  cin >> str1 >> str2;
  
  sort(str1.begin(), str1.end());
  sort(str2.begin(), str2.end(), greater<int>());
  
  if(str1 < str2) cout << "Yes";
  else cout << "No";
  /*
  index = min(str1.size(), str2.size());
  for(int i = 0; i < index; i++){
    if(str1.at(i) < str2.at(i)){
      chk == true;
    }else if(str1.at(i) > str2.at(i)){
      chk == false;
      break;
    }else{
      if(str1.size() < str2.size()){
        chk = true;
      }
    }
  }
  
  if(chk == true){
    cout << "Yes";
  }else{
    cout << "No";
  }
  
  */
}
