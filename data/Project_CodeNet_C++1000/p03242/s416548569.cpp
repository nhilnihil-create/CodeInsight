#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define PI 3.14159265359
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

int main() {
  string n;
  cin >> n;

  int a[3];

  rep(i, 3) {
    if (n[i] == '1')
      a[i] = 9;
    else
      a[i] = 1;

    cout << a[i];
  }

  return 0;
}

