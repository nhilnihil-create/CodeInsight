#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnHeight)
{
  int nHeightSiz;
  cin >> nHeightSiz;
  rvnHeight.resize(nHeightSiz);

  for (int& rnHeight : rvnHeight)
    cin >> rnHeight;
}

int fnMinWorkCnt(vector<int>& rvnHeight)
{
  int nWorkCnt = 0;
  int nPrevWorkCnt = -1;

  while (nPrevWorkCnt != nWorkCnt)
  {
    nPrevWorkCnt = nWorkCnt;
    int nBgn = 0;
  
    while (nBgn < rvnHeight.size() )
    {
      int nFoward = nBgn;

      while (nFoward < rvnHeight.size() &&
             rvnHeight[nFoward]            )
      {
        rvnHeight[nFoward]--;
        nFoward++;
      }

      if (nBgn != nFoward) nWorkCnt++;
      nBgn = nFoward + 1;
    }
  }
  return nWorkCnt;
}
 
int main()
{
  vector<int> vnHeight;

  fnInput(vnHeight);
  cout << fnMinWorkCnt(vnHeight) << endl;

  return 0;
}