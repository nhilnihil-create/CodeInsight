#include <iostream>
#include <string>

using namespace std;

int main() {
  string S;
  cin >> S;
  string h = S.substr(0, 2);
  string l = S.substr(2, 2);
  const char* result = "NA";
  if (("01" <= h) && (h <= "12") &&
      ("01" <= l) && (l <= "12")) {
    result = "AMBIGUOUS";
  } else if (("01" <= h) && (h <= "12")) {
    result = "MMYY";
  } else if (("01" <= l) && (l <= "12")) {
    result = "YYMM";
  }
  cout << result << endl;
  return 0;
}
