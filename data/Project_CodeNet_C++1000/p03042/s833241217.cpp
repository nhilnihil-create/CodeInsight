#include <iostream>
#include <string>
using namespace std;

int main(){
  string s;
  cin >> s;
  bool a = false, b = false;
  int x = (s[0] - '0') * 10 + (s[1] - '0');
  int y = (s[2] - '0') * 10 + (s[3] - '0');
  if (x > 0 && x <= 12) a = true;
  if (y > 0 && y <= 12) b = true;
  if (a && b) cout << "AMBIGUOUS" << endl;
  else if (a) cout << "MMYY" << endl;
  else if (b) cout << "YYMM" << endl;
  else        cout << "NA" << endl;
  
  return 0;
}