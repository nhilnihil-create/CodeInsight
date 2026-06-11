#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  int price = 700;
  for(int i=0;i<3;i++){
    if(S.at(i)=='o'){
      price = price + 100;
    }
  }
  cout << price;
  return 0;
}