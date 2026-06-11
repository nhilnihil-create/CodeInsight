#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  string S;
  cin >> S;
  
  int n = S.size(), ans = 0;
  for(int i = 0;i < n;i++){
    int cnt = 0;
    for(int j = i;j < n;j++){
      char b = S.at(j);
      if(b == 'A' || b == 'C' || b == 'G' || b == 'T') cnt++;
      else break;
    }
    ans = max(ans, cnt);
  }
  
  cout << ans << endl;
  
  return 0;
}