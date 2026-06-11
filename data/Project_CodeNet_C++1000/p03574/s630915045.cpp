#include <iostream>
#include <string>
 
int bomb_num(std::string S[], int y, int x, int H, int W)
{
  int result = 0;
  
  for(int i = y - 1; i <= y + 1; i++)
  {
    if(i < 0 || i >= H)
    {
      continue;
    }
    
    for(int k = x - 1; k <= x + 1; k++)
    {
      if(k < 0 || k >= W)
      {
        continue;
      }
      
      if(S[i][k] == '#')
      {
        result++;
      }      
    }
  } 
      
      
  return result;
}

int main()
{
  int H, W;
  std::string S[50];
  std::cin >> H >> W;
  
  for(int i = 0; i < H; i++)
  {
    std::cin >> S[i];
  }
  
  for(int i = 0; i < H; i++)
  {
    for(int k = 0; k < W; k++)
    {
      if(S[i][k] == '.')
      {
        std::cout << bomb_num(S, i, k, H, W);
      }
      else
      {
        std::cout << S[i][k];
      }
    }
    std::cout << "\n";
  }

  return 0;
}