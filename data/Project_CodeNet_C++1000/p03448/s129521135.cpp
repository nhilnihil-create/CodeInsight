#include <iostream>

int main()
{
  int A, B, C, X, count = 0;
  std::cin >> A; std::cin >> B; std::cin >> C; std::cin >> X;
  
  for (int a = 0; a <= A; a++)
  {
    for (int b = 0; b <= B; b++)
    {
      for (int c = 0; c <= C; c++)
      {
        int sum = 500*a + 100*b + 50*c;
        if (sum == X) count++;
      }
    }
  }
  
  std::cout << count;
  
  return 0;
}
    