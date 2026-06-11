#include<bits/stdc++.h>
using namespace std;
int main()
{
string s;
  cin >> s;
  int i,sw;
  sw=0;

  
  for(i=0;i<3;++i)
  {
  if(s.at(i)=='o') sw++;}
    
  cout <<700+100*sw;  
    
return 0;}