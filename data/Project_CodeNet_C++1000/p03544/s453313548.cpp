#include <iostream>

using namespace std;

int main()	{
  long long n;
  cin >> n;
  long long l_prev = 2;
  long long l_curr = 1;
  if (n == 0)	{
    cout << 2 << endl;
    return 0;
  }
  if (n == 1)	{
    cout << 1 << endl;
    return 0;
  }
  for (int i = 2; i <= n; i++)	{
    long long tmp = l_curr;
    l_curr = l_curr + l_prev;
    l_prev = tmp;
  }
  cout << l_curr << endl;
  return 0;
}