#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){

  string s;
  cin >> s;

  int n0 = 0;
  int n1 = 0;
  for(int i=0; i<s.size(); ++i){
    if(s[i] == '0') n0++;
    else n1++;
  }

  int ans = s.size() - abs(n0 - n1);
  cout << ans << endl;
  return 0;
}
