#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int t, x;
  cin >> t >> x;
  cout << fixed << setprecision(4) <<(float) t / x << endl;
  return 0;
}