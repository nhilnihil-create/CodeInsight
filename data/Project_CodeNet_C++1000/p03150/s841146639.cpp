#include <bits/stdc++.h>
using namespace std;

int main() {
  string key = "keyence";
  string str;
  string tmp;
  
  cin >> str;
  
  for(int i = 0; i < 8; i++){
    tmp = str.substr(0,i) + str.substr(str.size() - (7-i), 7-i);

    if(tmp == key){
      cout << "YES";
      return 0;
    }
  }
  
  cout << "NO";
}
