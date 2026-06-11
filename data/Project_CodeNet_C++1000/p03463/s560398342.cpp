#include <iostream>

#include <cmath>

using std::cin;
using std::cout;
using std::endl;

using std::abs;

int
main()
{
  int N, A, B;
  cin >> N >> A >> B;
  cout << (abs(A - B) % 2 ? "Borys" : "Alice") << endl;
  return 0;
}
