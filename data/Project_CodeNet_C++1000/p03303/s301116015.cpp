#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
using namespace std;
int main(void){
  string s;
  cin >> s;
  int n;
  cin >> n;
  int l;
  l = s.length();
  
  for(int i=0;i<l;i+=n){
    cout << s[i];
  }
  cout << endl;
  
  return 0;
}
