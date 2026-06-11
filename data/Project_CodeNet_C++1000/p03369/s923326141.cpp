#include <iostream>
using namespace std;
int main(){
  string s;
  cin >> s;
  int res = 700;
  for(int i = 0;i < s.length();++i) if(s[i] == 'o') res += 100;
  cout << res << endl;
}