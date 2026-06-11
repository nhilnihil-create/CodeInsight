#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long int;

int main() {
  string S;
  cin >> S;

  string year = S.substr(0, 4);
  string month = S.substr(5, 2);
  string day = S.substr(8, 2);

  auto F = [] (string year, string month, string day) {
      if (year < "2019") {
          return false;
      }
      if (year == "2019" && month < "04") {
          return false;
      }
      if (year == "2019" && month == "04" && day <= "30") {
          return false;
      }
      return true;
  };

  if (F(year, month, day)) {
      cout << "TBD" << endl;
  } else {
      cout << "Heisei" << endl;
  }
}
