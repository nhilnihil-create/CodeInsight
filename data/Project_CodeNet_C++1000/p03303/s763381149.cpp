#include <iostream>
using namespace std;

int main() {
  string s;
  int w;
  cin >> s >> w;
  string result;
  int i;
  for (i = 0; i < s.length(); i += w) {
    result.push_back(s.at(i));
  }
  cout << result << endl;
  return 0;
}
