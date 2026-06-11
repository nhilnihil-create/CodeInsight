#include <iostream>
 
int main()
{
  int N;
  long long result, L0 = 2, L1 = 1;
  std::cin >> N;

  if(N == 0)
  {
    result = L0;
  }
  else if(N == 1)
  {
    result = L1;
  }
  else
  {
    for(int i = 2; i <= N; i++)
    {
      result = L1 + L0;
      L0 = L1;
      L1 = result;
    }
  }

  std::cout << result;
  return 0;
}