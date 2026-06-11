#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define PI 3.14159265359
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string S;
  cin >> S;

  string month;
  month = S.substr(5, 6);
  int month_ = atoi(month.c_str());

  if (month_ >= 5)
    cout << "TBD" << endl;
  else
    cout << "Heisei" << endl;

  return 0;
}
