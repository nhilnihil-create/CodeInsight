#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
  int A[3];
  cin >> A[0] >> A[1] >> A[2];
  vector <int> a(3);
  a[0] = abs(A[0]-A[1]);
  a[1] = abs(A[0]-A[2]);
  a[2] = abs(A[1]-A[2]);
  sort(a.begin(), a.end());
  cout << a[0]+a[1] << endl;
  return 0;
}
