#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int cnt = 0;
  for (char c : s) cnt += c == 'o';
  cout << (15 - s.size() + cnt >= 8 ? "YES" : "NO") << endl;
}