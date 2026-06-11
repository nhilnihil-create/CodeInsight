#include<bits/stdc++.h>
using namespace std;
char c[5];
int n;
int main()
{
  for(int i=0; i<4; i++)
  {
    cin>>c[i];
    if(c[i]=='2')n++;
  }
  cout<<n;
  return 0;
}