#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  int rcount = 0;
  int bcount = 0;
  int i;
  for(i = 0; i < n; i++)
  {
    if(s.at(i) == 'R')
    {
      rcount++;
    }
    if(s.at(i) == 'B')
    {
      bcount++;
    }
  }
  if(rcount > bcount)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}