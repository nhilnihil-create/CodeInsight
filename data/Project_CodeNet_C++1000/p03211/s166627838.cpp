#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  int min = 99999;
  int res = 0;
  int x = 0;
  for(int i = 0; i < S.length() - 2; i++) {
    x = 100 * (S[i] - '0') + 10 * (S[i + 1] - '0') + (S[i + 2] - '0');
    if(min > abs(x - 753)) {
      min = abs(x - 753);
      res = x;
    }
  }
  cout << min << endl;
  return 0;
}
