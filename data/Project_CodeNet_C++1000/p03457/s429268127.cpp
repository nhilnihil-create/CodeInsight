#include <iostream>
#include <cstdlib>
int main()
{
  int N, t[100001] = {0}, x[100001] = {0}, y[100001] = {0};
  std::cin >> N;
  std::string result = "Yes";
  
  for(int i = 1; i <= N; i++)
  {
    std::cin >> t[i] >> x[i] >> y[i];  
  }
  
  for(int i = 1; i <= N; i++)
  {
    int time = t[i] - t[i-1];
    int dist = std::abs(x[i] - x[i - 1]) + std::abs(y[i] - y[i - 1]);
    if((time < dist) || (time % 2 != dist % 2))
    {
      result = "No";
      break;
    }
  }
    
  std::cout << result;
  return 0;
}