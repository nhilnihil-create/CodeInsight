#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <deque>

using namespace std;
const long long P = 1000000007;

int main() {
  string s;
  cin >> s;
  int flag = 0;
  if(s[5] == '1') {
    flag = 1;
  }
  if(s[6] != '4' && s[6] != '3' && s[6] != '2' && s[6] != '1') {
    flag = 1;
  }
  if(flag == 1) { 
    cout << "TBD" << endl;
  }else {
    cout << "Heisei" << endl;
  }
  return 0;
}
