#include <iostream>
 
int main()
{
  int N, alice = 0, bob = 0, cards[100];
  std::cin >> N;
  
  for(int i = 0; i < N; i++)
  {
    std::cin >> cards[i];
  }

  for(int i = 0; i < N; i++)
  {
    for(int k = 0; k < N; k++)
    {
      if(cards[i] > cards[k])
      {
        int temp = cards[i];
        cards[i] = cards[k];
        cards[k] = temp;
      }
    }
  }

  for(int i = 0; i < N; i++)
  {
    if(i % 2 == 0)
    {
      alice += cards[i];
    }
    else
    {
      bob += cards[i];
    }
  }  
  
  std::cout << alice - bob;
  return 0;
}