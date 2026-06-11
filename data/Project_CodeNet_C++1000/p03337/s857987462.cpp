#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int A, B;
  cin >> A >> B;

  long long max = A * (long long)B;
  if (max < A - B) max = A - B;
  if (max < A + B) max = A + B;

  cout << max << endl;
}