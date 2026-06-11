#include <iostream>
 
int main()
{
  int N, A, B, count = 0;
  std::cin >> N >> A >> B;
  
  for(int i = 1; i <= N; i++)
  {
    int sum = 0;
    for(int k = i; k > 0; k = k / 10)
    {
      sum += k % 10;
    }
    
    if(sum >= A && sum <= B)
    {
      count += i;
    }
  }
  
  std::cout << count;
  return 0;
}