#include <iostream>
using namespace std;

int func(int d, int a)
{
  int num = 1;
  int ret = 1;
  while(true)
  {
    if(num + a > d)
    {
      return ret;
    }
    num += a;
    ret++;
  }
}

int main()
{
  int n, d, x;
  cin >> n;
  cin >> d >> x;
  int a[n];
  for(int i = 0; i < n; ++i) cin >> a[i];
  
  int num = 0;
  for(int i = 0; i < n; ++i) num += func(d, a[i]);
  cout << num + x << endl;
}