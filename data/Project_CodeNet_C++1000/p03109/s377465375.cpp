#include <iostream>
#include <string>
using namespace std;
int main()
{
  string S;
  cin >> S;
  long long s = 0;
  for (int i = 0; i <= 3; i++) {
    s *= 10;
    s += (int)S[i] - (int)'0';
  }
  for (int i = 5; i <= 6; i++) {
    s *= 10;
    s += (int)S[i] - (int)'0';
  }
  for (int i = 8; i <= 9; i++) {
    s *= 10;
    s += (int)S[i] - (int)'0';
  }
  if (s <= 20190430) {
    cout << "Heisei" << endl;
  } else {
    cout << "TBD" << endl;
  }
  return 0;
}