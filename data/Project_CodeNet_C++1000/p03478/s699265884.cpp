#include <iostream>
 
int main()
{
  int N, A, B, sum = 0;
  std::cin >> N >> A >> B;
  
  for(int i = 1; i <= N; i++)
  {
    int digit_num_sum = 0;
    for(int digit_num = i; digit_num > 0; digit_num = digit_num / 10)
    {
      digit_num_sum += digit_num % 10;
    }
    
    if(digit_num_sum >= A && digit_num_sum <= B)
    {
      sum += i;
    }
  }
  
  std::cout << sum;
  return 0;
}