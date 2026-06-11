#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

string s;

int main() {
  cin >> s;

  for (int i = 0; i < (1 << 3); i++) {
    int cal = s[0] - '0';
    for (int j = 1; j < s.size(); j++) {
      if ((i >> (j - 1)) % 2 == 1) {
        cal += s[j] - '0';
      } else {
        cal -= s[j] - '0';
      }
    }

    if (cal == 7) {
      cout << s[0];
      for (int j = 1; j < s.size(); j++) {
        if ((i >> (j - 1)) % 2 == 1) {
          cout << "+" << s[j];
        } else {
          cout << "-" << s[j];
        }
      }
      cout << "=7" << endl;
      break;
    }
  }

  return 0;
}
