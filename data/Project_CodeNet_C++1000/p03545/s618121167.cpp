#include <bits/stdc++.h>
using namespace std;

long calc(string s) {
  long ret = 0;
  string tmp = "";
  char op = '+';
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '+' || s[i] == '-') {
      if (op == '+') {
        ret += atol(tmp.c_str());
      } else {
        ret -= atol(tmp.c_str());
      }
      op = s[i];
      tmp = "";
    } else {
      tmp += s[i];
    }
  }
  
  if (op == '+') {
    ret += atol(tmp.c_str());
  } else {
    ret -= atol(tmp.c_str());
  }

  return ret;
}

int main() {
  string S;
  cin >> S;
  
  int gapNum = S.size() - 1;

  for (int i = 0; i < (1 << gapNum); i++) { // ビット検索
    string s = S;
    int offset = 0;
    for (int j = 0; j < gapNum; j++) {
      if (i & (1 << j)) { // +
        s.insert(j + 1 + (offset++), "+");
      } else { // -
        s.insert(j + 1 + (offset++), "-");
      }
    }
    if (7 == calc(s)) {
      cout << s << "=7" << endl;
      break;
    }
  }
}
