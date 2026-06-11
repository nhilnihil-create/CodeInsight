#include <bits/stdc++.h>
using namespace std;

int main()
{
  int H,W;
  cin >> H >> W;
  vector<string> S(H);
  for(int i=0; i<H ; i++)
  {
    cin >> S.at(i);
  }
  
  const vector<int> dx = {0,0,1,-1};
  const vector<int> dy = {1,-1,0,0};
  int flag = 0;
  
  for(int i=0; i<H; i++)
  {
    for(int j=0; j<W; j++)
    {
      if(S.at(i).at(j) == '#')
      {
        flag = 1;
        for(int k=0; k<4; k++)
        {
          int ni = i + dx.at(k);
          int nj = j + dy.at(k);
          
          if(ni<0 || ni>=H) continue;
          if(nj<0 || nj>=W) continue;
          if(S.at(ni).at(nj) == '#') 
          {
            flag = 0;
          }
        }
      }
      if(flag == 1) break;
    }
    if(flag == 1) break;
  }
  if(flag == 1) cout << "No" << endl;
  else cout << "Yes" << endl;
  
}
            
        
      
  