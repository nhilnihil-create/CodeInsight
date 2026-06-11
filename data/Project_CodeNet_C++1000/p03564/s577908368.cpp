#include <iostream>
 
int main()
{
  int N, K, result = 1;
  std::cin >> N >> K;

  for(int i = 0; i < N; i++)
  {
    if(result < K)
    {
      result *= 2;
    }
    else
    {
      result += K;
    }
  }

  std::cout << result;
  return 0;
}