#include <iostream>

using namespace std;


int main()	{
  long long n;
  cin >> n;
  if (n <= 1)	{
    cout << n << endl;
    return 0;
  }
  long long i = 0;
  for (i = 1; i * i <= n; i++);
  cout << (i - 1) * (i - 1) << endl;
  return 0;
}