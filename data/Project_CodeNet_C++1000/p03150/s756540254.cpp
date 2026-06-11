#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  string s;
  cin >> s;

  string t = "keyence";

  // check removing last
  if (s.substr(0, t.size()) == t) {
    cout << "YES" << endl;
    return 0;
  }

  // check removing head
  if (s.substr(s.size() - t.size()) == t) {
    cout << "YES" << endl;
    return 0;
  }


  // check removing intermeditate
  if (s[0] != 'k') {
    cout << "NO" << endl;
    return 0;
  }

  // forward until diff
  int pivot = 1;
  int cursor = 0;
  for (int i = 1; i < s.size(); ++i) {
    if (s[i] == t[pivot])
      ++pivot;
    else {
      cursor = i;
      break;
    }
  }
  int rest_length = t.size() - pivot;
  if (s.substr(s.size() - rest_length) == t.substr(pivot)) {
    cout << "YES" << endl;
    return 0;
  }

  cout << "NO" << endl;

  return 0;
}