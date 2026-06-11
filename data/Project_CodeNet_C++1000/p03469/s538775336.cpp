#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;
int main(int argc, char* argv[]) {
  cin >> s;
  s[3] = '8';
  cout << s << endl;

  return 0;
}
