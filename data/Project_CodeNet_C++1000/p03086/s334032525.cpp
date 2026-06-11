#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;


int main(){
  string s;
  cin >> s;

  int ans = 0, maxNum = 0;
  
  for (int i=0; i<s.length(); i++){
    if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T'){
      ans += 1;
    }
    else{
      maxNum = max(maxNum, ans);
      ans = 0;
    }
  }
  
  maxNum = max(maxNum, ans);
  cout << maxNum;
  
  
  return 0;
}