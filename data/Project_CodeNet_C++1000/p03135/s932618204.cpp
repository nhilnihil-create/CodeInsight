#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  double t, x;
  cin >> t >> x;
  cout << fixed << setprecision(10) << t / x << endl;
}