#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
#include <sstream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;

  if ((s[0] - '0') + (s[1] - '0') + (s[2] - '0') + (s[3] - '0') == 7) {
    cout << s[0] << '+' << s[1] << '+' << s[2] << '+' << s[3] << '=' << 7 << endl;
    return 0;
  }
  if ((s[0] - '0') - (s[1] - '0') - (s[2] - '0') - (s[3] - '0') == 7) {
    cout << s[0] << '-' << s[1] << '-' << s[2] << '-' << s[3] << '=' << 7 << endl;
    return 0;
  }
  if ((s[0] - '0') + (s[1] - '0') - (s[2] - '0') + (s[3] - '0') == 7) {
    cout << s[0] << '+' << s[1] << '-' << s[2] << '+' << s[3] << '=' << 7 << endl;
    return 0;
  }
  if ((s[0] - '0') + (s[1] - '0') - (s[2] - '0') - (s[3] - '0') == 7) {
    cout << s[0] << '+' << s[1] << '-' << s[2] << '-' << s[3] << '=' << 7 << endl;
    return 0;
  }
  if ((s[0] - '0') - (s[1] - '0') + (s[2] - '0') - (s[3] - '0') == 7) {
    cout << s[0] << '-' << s[1] << '+' << s[2] << '-' << s[3] << '=' << 7 << endl;
    return 0;
  }
  if ((s[0] - '0') - (s[1] - '0') - (s[2] - '0') - (s[3] - '0') == 7) {
    cout << s[0] << '-' << s[1] << '-' << s[2] << '-' << s[3] << '=' << 7 << endl;
    return 0;
  }
  if ((s[0] - '0') + (s[1] - '0') + (s[2] - '0') - (s[3] - '0') == 7) {
    cout << s[0] << '+' << s[1] << '+' << s[2] << '-' << s[3] << '=' << 7 << endl;
    return 0;
  }
  if ((s[0] - '0') - (s[1] - '0') - (s[2] - '0') + (s[3] - '0') == 7) {
    cout << s[0] << '-' << s[1] << '-' << s[2] << '+' << s[3] << '=' << 7 << endl;
    return 0;
  }
  if ((s[0] - '0') - (s[1] - '0') + (s[2] - '0') + (s[3] - '0') == 7) {
    cout << s[0] << '-' << s[1] << '+' << s[2] << '+' << s[3] << '=' << 7 << endl;
    return 0;
  }
}