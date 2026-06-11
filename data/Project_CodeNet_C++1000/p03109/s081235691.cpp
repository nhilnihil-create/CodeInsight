#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  string S; cin >> S;
  int y = stoi(S.substr(0, 4));
  int m = stoi(S.substr(5, 2));
  int d = stoi(S.substr(8, 2));
  if (y < 2019) {
    cout << "Heisei" << endl;
    return 0;
  }
  if (m <= 4) {
    cout << "Heisei" << endl;
    return 0;
  }
  cout << "TBD" << endl;
}
