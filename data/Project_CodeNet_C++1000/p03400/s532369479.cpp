#include <iostream>

using namespace std;

int main() {
  int n, d, x;
  cin >> n >> d >> x;
  int vsum = 0;
  int a;
  while (cin >> a)
    vsum += 1 + (d - 1) / a;
  cout << vsum + x << endl;
}
