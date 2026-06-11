#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnLife)
{
  int nLiftSiz;
  cin >> nLiftSiz;
  rvnLife.resize(nLiftSiz);

  for (int& rnLife : rvnLife)
    cin >> rnLife;
}

int fnGcd(int nDividend, int nDivisor)
{
  while ( nDividend % nDivisor )
  {
    int nRemain = nDividend % nDivisor;
    nDividend = nDivisor;
    nDivisor  = nRemain;
  }
  return nDivisor;
}

int fnMinLife(const vector<int>& cnrvnLife)
{
  vector<int> vnSrtLift(cnrvnLife);
  sort(begin(vnSrtLift), end(vnSrtLift));

  int nMinLife = vnSrtLift[0];

  for (int i = 1; i < vnSrtLift.size(); i++)
  {
    int nDividend = vnSrtLift[i];
    int nDivisor  = nMinLife;
    nMinLife = min(nMinLife, fnGcd(nDividend, nDivisor));
  }
  return nMinLife;
}
 
int main()
{
  vector<int> vnLife;

  fnInput(vnLife);
  cout << fnMinLife(vnLife) << endl;

  return 0;
}