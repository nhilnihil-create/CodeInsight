#include <bits/stdc++.h>
using namespace std;

int main()
{
  int H,W;
  cin >> H >> W;
  int count = 0;
  vector<string> S(H);
  for(int i=0; i<H; i++)
  {
    cin >> S.at(i);
  }
    
  
  for(int i=0; i<H; i++)
  {
    for(int j=0; j<W; j++)
    {
      count = 0;
      if(S.at(i).at(j) == '.') //空きマスの場合
      {
          for(int k=max(0,j-1); k<=min(j+1,W-1); k++) //周りのマスを探す
          {
            for(int l=max(0,i-1); l<=min(i+1,H-1); l++)
            {
              if(S.at(l).at(k) == '#') count++;
            }
          }
        cout << count;
      }
      else
      {
        cout << '#';
      }
    }
    cout << endl;
  }
}     