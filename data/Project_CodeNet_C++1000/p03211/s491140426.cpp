#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
 
int main() {
  string s, c;
  cin >> s;
  
  int l = s.size(), ans = 0, minAns = 1000, p;
  
  for(int i = 0; i < l - 2; ++i)
  {
    c = s.substr(i, 3);
    stringstream str(c);
    str >> ans;
    p = abs(ans - 753);
    if(p < minAns)
      minAns = p;
  }
  cout << minAns;
  return 0;
}