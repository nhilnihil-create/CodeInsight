#include <iostream>
#include <string>
using namespace std;

int main(){

  //initialization
  string s;
  int price = 700;

  //input
  cin >> s;
  
  //solver
  for(int i=0; i < s.size(); i++) if(s[i] == 'o') price += 100;

  //output
  cout << price << "\n";
}
