#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  
  vector<int>N(S.size());
  for (int i = 0; i < S.size(); i++) {
    N.at(i) = S.at(i) - '0';
  }
  
  int count = 0;
  for (int i = 0; i < S.size(); i++) {
    if (i == 0){
      if (N.at(i) != 17){
        cout << "WA" << endl;
        return 0;
      }
    }
    else if (i == 1 || i == S.size() - 1){
      if (N.at(i) < 49){
        cout << "WA" << endl;
        return 0;
      }
    }
    else {
      if (N.at(i) == 19){
        count++;
      }
      else if (N.at(i) < 49){
        cout << "WA" << endl;
        return 0;
      }
    }
  }
  
  if (count == 1){
    cout << "AC" << endl;
  }
  else {
    cout << "WA" << endl;
  }
}
      
  

