#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
  int n,a,b,M,m;
  cin >> n;
  cin >> a;
  cin >> b;
  M = min(a,b);
  m = a + b - n;
  if(m < 0) m = 0;
  cout << M << " " << m << "\n";
  return 0;
}