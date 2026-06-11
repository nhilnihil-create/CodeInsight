#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,sw,i,min;
  sw=0;
  cin >> n;
  string h;
  cin >> h;
  
  for(i=0;i<n;++i)
  {
  if(h.at(i)=='E') sw++;
  }
  
  min=sw;
  
  for(i=1;i<n+1;i++)
  {
  if(h.at(i-1)=='W') sw++;
  if(h.at(i-1)=='E') sw--;
  if(sw < min) min=sw;
  }
  
  printf("%d",min);
  
return 0;
}