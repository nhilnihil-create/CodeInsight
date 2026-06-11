#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long n, p, i;
  cin >> n >> p;
  long long ans = 1;
  long long count = 0;
  for(i = 2; i <= 1000000; i++)
  {
    while(p % i == 0)
    {
      p /= i;
      count++;
    }
    count /= n;
    while(count > 0)
    {
      ans *= i;
      count--;
    }
    count = 0;
  }
  if(p != 1 && n == 1)
  {
    ans *= p;
  }
  cout << ans << endl;
}