#include <iostream>

int main()
{
  int A, B, C, X, count = 0;
  std::cin >> A >> B >> C >> X;
  
  for(int i = 0; i <= A; i++)
  {
    for(int j = 0; j <= B; j++)
    {
      for(int k = 0; k <= C; k++)
      {
        if((i*500 + j*100 + k*50) == X)
        {
          count++;
        }
      }
    }
  }
  
  std::cout << count;
  return 0;
}