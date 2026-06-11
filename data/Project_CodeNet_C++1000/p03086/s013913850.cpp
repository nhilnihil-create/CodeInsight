#include <bits/stdc++.h>
using namespace std;

int main() {
 string input; cin >> input;
 string check = "ACGT";
 
 int ans = 0;
 int tempAns = 0;
 for(int i = 0; i < input.length(); i++) {
  if(check.find(input.at(i)) != std::string::npos) {
   tempAns++;
  } else {
   tempAns = 0;
  }
   if( ans < tempAns) {
     ans = tempAns;
   }
 }
  
  cout << ans << endl;
  
  return 0;
}