#include <iostream>
#include <cmath>

using namespace std;

int main()	{
  int n, m;
  cin >> n >> m;
  long long time = ((n - m) * 100 + 1900 * m) * pow(2, m);
  cout << time << endl;
  return 0;
}