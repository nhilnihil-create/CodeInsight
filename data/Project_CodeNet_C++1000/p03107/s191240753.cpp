#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  string S;
  cin >> S;
  
  int zero = 0, one = 0;
  for(int i = 0;i < S.size();i++){
    if(S.at(i) == '0') zero++;
    if(S.at(i) == '1') one++;
  }
  
  cout << min(zero, one) * 2 << endl;
  
  return 0;
}