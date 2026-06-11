#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int main(void) {
  string s;
  int k;
  cin >> s >> k;
  s += 'x';
  for(int i = 0; i < k; i++) {
    if(s[i] == 'x') {
      cout << 1 << endl;
      return 0;
    }
    if(s[i] != '1') {
      cout << s[i] << endl;
      return 0;
    }
    if(i == k - 1) {
      cout << s[i] << endl;
    }
  }

  return 0;
}
