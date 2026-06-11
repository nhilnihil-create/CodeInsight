#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v(3);
  for (int i = 0; i < 3; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  int d = v[2] - v[1] + v[2] - v[0];
  if (v[0] % 2 == v[1] % 2 && v[1] % 2 == v[2] % 2) {
    cout << d / 2 << endl;
  } else if (v[0] % 2 == v[1] % 2) {
    cout << d / 2 << endl;
  } else {
    cout << d / 2 + 2 << endl;
  }
}
