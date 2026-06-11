#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int k;
  cin >> k;
  if(k % 2 == 0) cout << (k / 2) * (k / 2) << "\n";
  else cout << (k / 2) * (k / 2 + 1) << "\n";
}
