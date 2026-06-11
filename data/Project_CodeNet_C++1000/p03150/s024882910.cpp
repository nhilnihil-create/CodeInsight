#include <algorithm>
#include <iostream>

using namespace std;

const string K{"keyence"};

int main() {
  string S;
  cin >> S;
  bool cond = false;
  for (size_t i = 0; i != K.size(); ++i) {
    if (equal(begin(S), begin(S) + i, begin(K)) &&
        equal(rbegin(S), rbegin(S) + K.size() - i, rbegin(K))) {
      cond = true;
      break;
    }
  }
  cout << (cond ? "YES" : "NO") << endl;
  return 0;
}
