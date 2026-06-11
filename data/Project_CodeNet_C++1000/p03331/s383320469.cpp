#include <bits/stdc++.h>
using namespace std;

int SumOfDigits(int a)
{
  int sum = 0;
  while (a > 0)
  {
    sum += a % 10;
    a /= 10;
  }
  return sum;
}

int main()
{
  int N;
  cin >> N;
  int ans = 900;

  for (int i = 1; i < N; i++)
  {
    int a = SumOfDigits(i) + SumOfDigits(N - i);
    if(ans > a){
      ans = a;
    }

  }
  cout << ans << endl;
}
