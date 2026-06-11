#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b;
    string r;
    cin >> a >> b ;
  if(a * b % 2 == 1) r = "Odd";
  else r = "Even";
  cout <<  r;
}
