#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  string a;
  cin >> a;
  if(a.at(5)>'0')cout << "TBD";
  else if(a.at(6)>'4')cout << "TBD";
  else cout << "Heisei";
}