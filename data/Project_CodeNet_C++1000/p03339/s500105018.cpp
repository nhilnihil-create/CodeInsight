#include <bits/stdc++.h>
using namespace std;
      
int main()
{
  int N;
  string S;
  cin >> N >> S;
  
  //初期値の設定
  int N0=0;
  int del = 0;
  int NE = 0;
  int NS = 0;
  if(S.at(0) == 'W') NS += 1;
  
  for(int i=1; i<N; i++)
  {
    if(S.at(i) == 'E')
    {
      NE++;
      N0++;
    }
    
    del = min(del,NS-NE);
    if(S.at(i) == 'W') NS++;
  }
  
  cout << N0 + del << endl;
}
  
  
  
  