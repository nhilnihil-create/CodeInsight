#include <iostream>

using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int result;
  if (A <= 5) result = 0;
  else if (A <= 12) result = B / 2;
  else result = B;
  cout << result << endl;
  return 0;
}
