#include <iostream>
using namespace std;

int func(int s)
{
  int n[10000] = {0};
  int ans = 1;
  n[s] = 1;

  while(true)
  {
    ans++;
    if(s%2 == 0)
    {
      s /=  2;
    }
    else
    {
      s = s * 3 + 1;
    }

    if(n[s] != 0)
    {
      return ans;
    }
    n[s]++;
  }
}

int main()
{
  int s;
  cin >> s;
  int ans = func(s);
  cout << ans << endl;
}