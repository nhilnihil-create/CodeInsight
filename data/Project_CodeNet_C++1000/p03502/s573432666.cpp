#include <iostream>
 
int main()
{
  int N, sum = 0;
  std::cin >> N;

  for(int temp = N; temp >= 1; temp /= 10)
  {
      sum += temp % 10;
  }

  if(N % sum == 0)
  {
    std::cout << "Yes";
  }
  else
  {
    std::cout << "No";
  }
  
  return 0;
}