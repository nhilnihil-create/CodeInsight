#include<iostream>
using namespace std;

int main()
{
  int n, a, b;
  cin >> n >> a >> b;
  
  int sum = 0;
  for (int i = 1; i <= n; i ++)
  {
    int sum_digits = 0;
    int tmp = i;
    while (tmp > 0)
    {
      sum_digits += tmp % 10;
      tmp /= 10;
    }
    if (sum_digits >= a && sum_digits <= b) sum += i;
  }
  
  cout << sum;
  return 0;
}
