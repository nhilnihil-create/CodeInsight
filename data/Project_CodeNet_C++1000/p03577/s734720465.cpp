#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
using namespace std;
int main(void){
  string s;
  cin >> s;
  
  int n = s.length();
  
  cout << s.substr(0,n-8) << endl;
  
  return 0;
}
