#include <iostream>
 
int main()
{
  long long N, result = 1;
  std::cin >> N;

  for(long long i = N / 2; i > 0; i--)
  {
    if(i * i <= N)
    {
      result = i * i;
      break;
    }
  }

  std::cout << result;
  return 0;
}