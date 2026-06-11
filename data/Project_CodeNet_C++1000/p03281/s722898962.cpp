#include <iostream>

using namespace std;

int main()
{
  int n; cin >> n;
  int cnt = 0;
  for (int i = 105; i <= n; i = i + 2)
  {
    int c = 0;
    for (int j = 1; j <= i; j++)
    {
      if (i % j == 0) c++;
    }
    if (c == 8) cnt++;
  }
  cout << cnt << endl;
}
