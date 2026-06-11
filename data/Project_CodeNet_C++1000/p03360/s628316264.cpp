#include <iostream>
using namespace std;

int main()
{
  int A, B, C, K, *mx;

  cin >> A >> B >> C >> K;
  if (A > B) mx = &A;
  if (B > A) mx = &B;
  if (C > *mx) mx = &C;
  for (int i = 1; i <= K; i++)
    *mx *= 2;
  cout << A + B + C << endl;
  return 0;
}
