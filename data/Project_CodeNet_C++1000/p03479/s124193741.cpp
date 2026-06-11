#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  long long x,y;
  cin >> x >> y;
  int i = 1;
  long long num = 1; 
  while(true) {
    if(num > y/x) {
      break;
    }
    num *= 2;
    i++; 
  }
  cout << i-1 << endl;
  return 0;
}