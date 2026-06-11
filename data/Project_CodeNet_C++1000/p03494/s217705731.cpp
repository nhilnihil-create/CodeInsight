#include <iostream>

int main()
{
  int N = 0;
  int count = 0;
  int A[201];
  
  std::cin >> N;
  for (int i = 0; i < N; i++)
    std::cin >> A[i];
  
  while(true)
  {
    bool isOdd = false;
    for (int i = 0; i < N; i++)
      if (A[i] % 2) isOdd = true;
    
    if (isOdd)
      break;
    
    for (int i = 0; i < N; i++)
      A[i] /= 2;
    
    count++;
  }
  
  std::cout << count;
  
  return 0;
}