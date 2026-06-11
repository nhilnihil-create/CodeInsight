#include <iostream>
using namespace std;

int main(void){
  string s;
  int sum, flg;

  cin >> s;
  sum = 0; flg = 1;
  for (int i=0; i<s.size(); i++){
    sum += s[i]-'0';
    if (i!=0) flg &= s[i]=='9';
  }
  if (flg) cout << sum << endl;
  else cout << ((s[0]-'0'-1)+9*(s.size()-1)) << endl;
  
  return 0;
}
