#include <iostream>
using namespace std;
int main(){
  string s;
  cin >> s;
  int i;
  int x = 700;
  for(i=0;i<3;i++){
    if(s[i]=='o') x += 100;
  }
  cout << x << "\n";
  return 0;
}