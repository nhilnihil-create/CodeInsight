#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
using namespace std;
int main(void){
  string s;
  cin >> s;
  
  int n = s.length();
  
  if(n == 2)
    cout << s << endl;
  else{
    for(int i=2;i>=0;i--){
      cout << s[i];
    }
    cout << endl;
  }
  
  return 0;
}

  
  