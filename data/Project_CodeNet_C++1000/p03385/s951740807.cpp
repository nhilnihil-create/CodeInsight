#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  string S;
  cin >> S;
  
  bool a = false;
  bool b = false;
  bool c = false;
  rep(i, S.size()) {
    switch(S[i]) {
    case 'a':
      a = true;
      break;
    case 'b':
      b = true;
      break;
    case 'c':
      c = true;
      break;
    }
  }

  if (a && b && c) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
