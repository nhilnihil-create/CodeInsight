#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES
#include <math.h>

int main() {
  int a, b, ans;
  cin >> a >> b;

  ans = a * b;
  if (ans / 2.0 == ans / 2) {
    cout << "Even" << endl;
  }
  else {
    cout << "Odd" << endl;
  }
}
