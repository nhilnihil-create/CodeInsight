#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
  string S;
  
  cin >> S;
  
  int ans = 1000;
  for(int i = 2;i < S.size();i++){
    int X = 100*(S.at(i-2)-'0') + 10*(S.at(i-1)-'0') + (S.at(i)-'0');
    ans = min(ans, abs(753 - X));
  }
  
  cout << ans << endl;
  
  return 0;
}