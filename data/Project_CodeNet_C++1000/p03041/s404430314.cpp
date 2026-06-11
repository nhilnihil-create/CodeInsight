#include <iostream>
using namespace std;

int main(){
  string c;
  int a,b;
  cin >> a >>b >> c;
  c.at(b-1) += 32;
  cout << c;
}