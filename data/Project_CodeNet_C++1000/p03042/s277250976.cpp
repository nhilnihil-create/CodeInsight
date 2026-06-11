#include <iterator>
#include <list>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;

int main() {
  string S; cin >> S;

  int first = stoi(S.substr(0, 2));
  int second = stoi(S.substr(2));

  if (first >= 1 && first <= 12) {
    if (second >= 1 && second <= 12) {
      cout << "AMBIGUOUS" << endl;
    } else {
      cout << "MMYY" << endl;
    }
  } else {
    if (second >= 1 && second <= 12) {
      cout << "YYMM" << endl;
    } else {
      cout << "NA" << endl;
    }
  }

  return 0;
}
