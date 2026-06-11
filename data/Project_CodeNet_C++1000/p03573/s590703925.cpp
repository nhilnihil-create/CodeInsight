#include <iostream>
using namespace std;
int main()
{
  int A, B, C;
  cin >> A >> B >> C;
  if (A==B) cout << C;
  if (B==C) cout << A;
  if (A==C) cout << B;
  cout << endl;
  return 0;
}