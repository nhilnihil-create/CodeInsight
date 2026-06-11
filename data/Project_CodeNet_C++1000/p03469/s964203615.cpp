#include <math.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define PI 3.14159265359
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

int main() {
  string S;
  cin >> S;

  string ans;

  ans = "2018" + S.substr(4, 6);

  cout << ans << endl;

  return 0;
}
