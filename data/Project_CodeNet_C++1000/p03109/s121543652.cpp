#include <iostream>
using namespace std;
int main(){
  string s;
  cin >> s;
  if(s[5]=='0'&&(s[6]=='1'||s[6]=='2'||s[6]=='3')) cout << "Heisei" << "\n";
  else if(s[6]=='4'&&(s[8]=='0'||s[8]=='1'||s[8]=='2'||(s[8]=='3'&&s[9]=='0'\
))) cout << "Heisei" << "\n";
  else cout << "TBD" << "\n";
  return 0;
}