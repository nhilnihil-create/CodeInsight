#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;
  int num = 0;
  num = num * 10 + str[2] - '0';
  num = num * 10 + str[3] - '0';
  int num1 = 0;
  num1 = num1 * 10 + str[0] - '0';
  num1 = num1 * 10 + str[1] - '0';
  if (num >= 1 && num <= 12) {
    if (num1 >= 1 && num1 <= 12) {
      cout << "AMBIGUOUS" << endl;
    } else {
      cout << "YYMM" << endl;
    }
  } else if (num1 >= 1 && num1 <= 12) {
    if (num >= 1 && num <= 12) {
      cout << "AMBIGUOUS" << endl;
    } else {
      cout << "MMYY" << endl;
    }
  } else {
    cout << "NA" << endl;
  }
}