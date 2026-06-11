#include <iostream>
using namespace std;

int main(){
  string s;
  cin >> s;
  if(s[0] != 'A'){
    cout << "WA";
    return 0;
  }
  int cntC = 0,n = s.length();
  for(int i = 2; i < n -1; i++){
    if(s[i] == 'C')cntC++;
  }
  if(cntC > 1 || cntC == 0){
    cout << "WA";
    return 0;
  }
  for(int i = 0; i < n; i++){
    if(s[i] == 'A' || s[i] == 'C') continue;
    if(s[i] - 65 + 1 >= 1 && s[i] - 65 + 1 <= 26){
      cout << "WA";
      return 0;
    }
  }
  cout << "AC";
  return 0;
}
  
