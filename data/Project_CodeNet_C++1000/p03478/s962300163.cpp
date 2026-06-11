#include <iostream>

int sumDigit(int n);

int main()
{
  int N, A, B;
  std::cin >> N >> A >> B;
  
  int ans = 0;
  for (int n = 1; n <= N; n++)
  {
    int sum = sumDigit(n);
    if (A <= sum && sum <= B)
      ans += n;
  }
  
  std::cout << ans;
  
  return 0;
}

int sumDigit(int n)
{
  int sum = 0;
  while (n != 0)
  {
    sum += n % 10;
    n /= 10;
  }
  
  return sum;
}