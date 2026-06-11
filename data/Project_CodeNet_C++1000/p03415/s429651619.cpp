#include<bits/stdc++.h>
using namespace std;
int main()
{
  char mat[3][3];
  int i,j;
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      cin>>mat[i][j];
    }
  }
  string s ="";
  s=s+mat[0][0]+mat[1][1]+mat[2][2];
  cout<<s;
  return 0;
}