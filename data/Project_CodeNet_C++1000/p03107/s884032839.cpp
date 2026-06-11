#include <bits/stdc++.h>
using namespace std;

void fnInput(string& rsColor)
{
  cin >> rsColor;
}

int fnMaxRemove(string sColor)
{
  int nCnt0 = 0;
  int nCnt1 = 0;

  for (int i = 0; i < sColor.size(); i++)
  {
    if (sColor[i] == '0') nCnt0++;
    if (sColor[i] == '1') nCnt1++;
  }
  return min(nCnt0, nCnt1) * 2;
}
 
int main()
{
  string sColor;

  fnInput(sColor);
  cout << fnMaxRemove(sColor) << endl;

  return 0;
}