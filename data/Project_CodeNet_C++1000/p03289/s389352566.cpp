#include <bits/stdc++.h>
using namespace std;


int main() {
  string S;
  bool flag = false;
  cin >> S;
  if(S.at(0) == 'A'){
    for(int i=1;i<S.size();++i){
      if(isupper(S.at(i))){
        if(i > 1 && i != S.size() - 1 ){
          if(S.at(i) == 'C' && !flag){
            flag = true;
          }else{
            cout << "WA" << endl;
            return 0;
          }
        }else{
          cout << "WA" << endl;
          return 0;
        }
      }
    }
  }else{
    cout << "WA" << endl;
    return 0;
  }

    if(flag){
      cout << "AC" << endl;
      return 0;
    }else{
      cout << "WA" << endl;
      return 0;
    }
}
