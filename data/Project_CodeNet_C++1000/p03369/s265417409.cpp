#include<iostream>
using namespace std;

int main() {
  char s[3];
  cin >> s;
  int c;
  if (s[0] == 'o') ++c;
  if (s[1] == 'o') ++c;
  if (s[2] == 'o') ++c;
  cout << 700 + c*100 << endl;
  return 0;
}
