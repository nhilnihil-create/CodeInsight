#include <iostream>
#include <math.h>
using namespace std;
#define prt(var) cout << (var) << endl;

int main() {
  string s;
  cin>>s;
  
  bool ok=false;
  if(s[0]==s[1] && s[1]==s[2]) ok=true;
  if(s[2]==s[3] && s[1]==s[2]) ok=true;
  
  prt(ok?"Yes":"No");
}