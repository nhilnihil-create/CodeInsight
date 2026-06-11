#include <iostream>

int main()
{
  int N, Y, result_10000 = -1, result_5000 = -1, result_1000 = -1;
  std::cin >> N >> Y;
  
  for(int i = 0; i <= N; i++)
  {
    for(int j = 0; j <= N - i; j++)
    {
      int k = N - i - j;
      if(Y == (10000*i + 5000*j + 1000*k))
      {
        result_10000 = i;
        result_5000 = j;
        result_1000 = k;
      }
    }
  }
  
  std::cout << result_10000 << " " << result_5000 << " " << result_1000;
  return 0;
}