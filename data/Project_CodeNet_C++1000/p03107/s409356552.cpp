#include <iostream>
#include <string>
using namespace std;
int main() {
  string s;
  cin >> s;
  int c = 0;
  for(int i = 0; i < (int)s.size(); i++) {
    if (s[i] == '0') c++;
  }
  cout << min(c,(int)s.size()-c)*2 << endl;
  return 0;
}