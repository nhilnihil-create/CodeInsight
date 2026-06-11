#include<bits/stdc++.h>
using namespace std;
int main()
{
string s1,s2;
  
  cin >> s1 >> s2;
  
  int sw=0;
  for(int i=0;i<3;++i)
  {if(s1.at(i)==s2.at(2-i)) sw++;
  }
  
  if(sw==3) cout <<"YES";
  else cout <<"NO";

return 0;}