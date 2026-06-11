#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main(){
  string s; cin >> s;

  int a = 0, b = 0, c = 0;

  for(const char ch : s){
    switch (ch){
      case 'a':
        a++;
        break;
      case 'b':
        b++;
        break;
      case 'c':
        c++;
        break;
    }
  }  

  if(abs(a-b) <= 1 && abs(b-c) <= 1 && abs(c-a) <= 1){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }

  return 0;
}
