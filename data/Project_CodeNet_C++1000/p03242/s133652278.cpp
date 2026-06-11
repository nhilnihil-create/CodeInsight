#include<bits/stdc++.h>
using namespace std;
int main()
{
vector<char> h(3);
  for(int i=0;i<3;++i)
  {
  cin >> h.at(i);
  if(h.at(i)=='1') h.at(i)='9';
  else if(h.at(i)=='9') h.at(i)='1';
  cout << h.at(i);
  }
}