#include <iostream>
using namespace std;

int func(int n)
{
  int ret = 0;
  while(n > 0){
    ret += n % 10;
    n = n / 10;
  }
  return ret;
}

int main()
{
  int n, a, b;
  cin >> n >> a >> b;
  int ans = 0;
  for(int i = 1; i <= n; ++i)
  {
    int tmp = func(i);
    if(tmp >= a && tmp <= b) ans += i;
  }
  
  cout << ans << endl;
}