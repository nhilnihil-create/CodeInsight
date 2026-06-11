#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string s;
  cin >> s;
  if(s[5] == '1' || (s[5] == '0' && s[6] >= '5')) cout << "TBD\n";
  else cout << "Heisei\n";
}