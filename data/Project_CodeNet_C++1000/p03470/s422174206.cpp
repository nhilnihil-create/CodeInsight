#include <iostream>
 
int main()
{
  int N, mochis[100], count = 1;
  std::cin >> N;
  
  for(int i = 0; i < N; i++)
  {
    std::cin >> mochis[i];
  }
  
  for(int i = 0; i < N; i++)
  {
    for(int k = 0; k < N; k++)
    {
      if(mochis[i] > mochis[k])
      {
        int temp = mochis[i];
        mochis[i] = mochis[k];
        mochis[k] = temp;
      }
    }
  }

  for(int i = 0; i < N - 1; i++)
  {
    if(mochis[i] != mochis[i + 1])
    {
      count++;
    }
  }  
  
  std::cout << count;
  return 0;
}