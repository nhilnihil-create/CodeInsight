#include <iostream>
using namespace std;

int main(){
  string s;
  int counter = 0;
  cin >> s;

  for(int i=0; i<s.size(); i++){
    if (s[i] == '1'){
      counter++;
    }
  }
  cout << counter;
} 