#include <iostream>
#include <string>

using namespace std;

int main(void){
  string str;
  
  cin >> str;
  
  int len = str.length();
  
  cout << str.substr( 0, len-8 ) << endl;
  
  return 0;
}