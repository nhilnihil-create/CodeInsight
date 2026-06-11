#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string hinaarare;
  int count_P = 0, count_W = 0;
  int count_G = 0, count_Y = 0, zeroflag = 0;

  
  for(int i = 0 ; i < N; i++)
  {
    cin >> hinaarare;
    if(hinaarare == "P")
    {
      count_P++;
    }
    else if(hinaarare == "W")
    {
      count_W++;
    }
    else if(hinaarare == "G")
    {
      count_G++;
    }
    else if(hinaarare == "Y")
    {
      count_Y++;
    }
  }
  if(count_P == 0)
  {
    zeroflag++;
  }
  if(count_W == 0)
  {
    zeroflag++;
  }
  if(count_G == 0)
  {
    zeroflag++;
  }
  if(count_Y == 0)
  {
    zeroflag++;
  }
    
  if(zeroflag == 0)
  {
    cout << "Four" << endl;
  }
  else if(zeroflag == 1)
  {
    cout << "Three" << endl;
  }
}

