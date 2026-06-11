#include <iostream>
using namespace std;
int main() {
  int a,b;
  cin >> a >> b;
  if (abs(a-b) <= 1) cout << "Yay!" << endl;
  else cout << ":(" << endl;
  return 0;
}