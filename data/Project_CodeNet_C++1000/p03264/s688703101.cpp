#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define PI 3.14159265359
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

int main() {
  int K;
  cin >> K;

  int ans;

  ans = (K - (K / 2)) * (K / 2);

  cout << ans << endl;

  return 0;
}
