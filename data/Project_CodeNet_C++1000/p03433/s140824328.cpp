#include <iostream>
using namespace std;
int main()
{
  int n, a;
  cin >> n >> a;
  int ans = 0;
  ans = n % 500;

  if (ans <= a)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

  return 0;
}
