#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  string s;
  cin >> a >> b >> s;
  if(s.size() == a+b+1 && s.at(a) == '-' ){
    bool ans = true;
    for(int i = 0; i < a; i++){
      if(s.at(i) == '-' ){
        ans = false;
        break;
      }
    }
    for(int i = a+1; i < a+b+1; i++){
      if(s.at(i) =='-'){
        ans = false;
        break;
      }
    }
    if(ans && s.size() != 1){
      cout << "Yes" << endl;
      return 0;
    } else {
      cout << "No" << endl;
      return 0;
    }
  } else {
    cout << "No" << endl;
  }
}