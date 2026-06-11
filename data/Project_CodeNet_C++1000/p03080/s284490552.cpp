#include <iostream>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  for (int i = 0; i < s.size(); i++) {
  	if (s[i] == 'R') n--;
  }
  if (n < (s.size() + 1) / 2) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}