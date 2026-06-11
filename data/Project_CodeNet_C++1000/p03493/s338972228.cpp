#include <iostream>

using namespace std;

int main()	{
  int a;
  cin >> a;
  int n = 0;
  for (int i = 0; i < 3; i++)	{
    if (a & (1<<i)) n++;
  }
  cout << n << endl;
  return 0;
}