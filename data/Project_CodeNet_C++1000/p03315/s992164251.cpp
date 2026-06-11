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

  int len_S = S.size();

  int count = 0;

  rep(i, len_S) {
    if (S[i] == '+')
      count++;
    else
      count--;
  }

  cout << count << endl;

  return 0;
}
