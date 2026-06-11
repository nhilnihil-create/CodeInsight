#include <iostream>
using namespace std;

int main(){
  int count = 0, i;
  string s;
  cin >> s;
  for(i=0; i<4; i++){
    if(s[i] == '2') count++;
  }
  cout << count;
  return 0;
}