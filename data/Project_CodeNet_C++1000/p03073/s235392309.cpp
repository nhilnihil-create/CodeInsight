#include <bits/stdc++.h>
using namespace std;

void fnInput(string& rsColor)
{
  cin >> rsColor;
}

int fnChangeCnt(string sBgnColor, string sColor)
{
  int nChangeCnt = 0;

  for (int i = 0; i < sColor.size(); i++)
  {
    int n = i % 2;
    if (sColor[i] != sBgnColor[n]) nChangeCnt++;
  }
  return nChangeCnt;
}

int fnMinChangeCnt(string sColor)
{
  int nMinChangeCnt = INT_MAX;
  string sRvsColor(sColor);
  reverse(begin(sColor), end(sColor));

  nMinChangeCnt = min(nMinChangeCnt, fnChangeCnt("01", sColor));
  nMinChangeCnt = min(nMinChangeCnt, fnChangeCnt("10", sColor));
  nMinChangeCnt = min(nMinChangeCnt, fnChangeCnt("01", sRvsColor));
  nMinChangeCnt = min(nMinChangeCnt, fnChangeCnt("10", sRvsColor));

  return nMinChangeCnt;
}
 
int main()
{
  string sColor;
  fnInput(sColor);
  cout << fnMinChangeCnt(sColor) << endl;

  return 0;
}