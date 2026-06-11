#include <iostream>
using namespace std;

int main() {
  int n, z, w; cin >> n >> z >> w;
  for (int i = 0; i < n-2; i++) { int a; cin >> a; }
  if (n == 1) {
    int a; cin >> a;
    cout << abs(a - w) << endl;
  }
  else {
    int a1, a2; cin >> a1 >> a2;
    cout << max(abs(a1 - a2), abs(a2 - w)) << endl;
  }
}