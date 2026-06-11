#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int s;
  int m[1000000];
  int count=1;

  cin >> s;

  int a = s;
  m[a]++;
  while (true)
  {
    count++;
    if (a%2==0)
    {
      a=a/2;
    }else
    {
      a=3*a+1;
    }
    if (m[a]==0)
    {
      m[a]++;
    }else
    {
      break;
    }
  }
  cout << count << "\n";

  return 0;
}