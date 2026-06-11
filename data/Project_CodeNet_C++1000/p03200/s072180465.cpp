#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  int index = 0;
  long long cnt = 0;
  long long bCnt = 0;
  bool chk = true;
  
  cin >> str;
  
  index = str.size()-1;
  
  for(int i = 0; i <= index; i++){
    if(str.at(i) == 'W'){
      cnt += bCnt;
    }else{
      bCnt++;
    }
  }
  
  cout << cnt;
}
