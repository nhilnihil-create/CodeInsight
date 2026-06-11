#include <iostream>
using namespace std;

int main(void) {
  int hour;
  cin >> hour;
  hour = 24 - hour;
  hour += 24;
  cout << hour << endl;
  
  return 0;
}