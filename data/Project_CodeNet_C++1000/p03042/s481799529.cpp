#include <iostream>
#include <string>
#include <set>

using namespace std;

const set<string> MM = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};

int main() {
  string S;
  cin >> S;
  if (MM.count(S.substr(0, 2)) != 0) {
    if (MM.count(S.substr(2, 2)) != 0) {
      cout << "AMBIGUOUS" << endl;
    } else {
      cout << "MMYY" << endl;
    }
  } else if (MM.count(S.substr(2, 2)) != 0) {
    cout << "YYMM" << endl;
  } else {
    cout << "NA" << endl;
  }
  
  return 0;
}
