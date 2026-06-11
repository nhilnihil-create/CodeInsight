
#include <iostream>
using namespace std;

template <typename T>
T _min(
  const T & lhs
  , const T & rhs
)
{
  return ((lhs < rhs) ? lhs : rhs);
}

int main()
{
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  cout << _min(A, B) + _min(C, D);
  return 0;
}
