#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s, t;

int main(int argc, char* argv[]) {
  cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end(), greater<char>());

  for (int i = 0; i < min(s.size(), t.size()); i++) {
    if (s[i] < t[i]) {
      cout << "Yes" << endl;
      return 0;
    } else if (s[i] > t[i]) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << (s.size() < t.size() ? "Yes" : "No") << endl;

  return 0;
}
