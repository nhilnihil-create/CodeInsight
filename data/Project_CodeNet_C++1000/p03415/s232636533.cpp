#include<iostream>
using namespace std;
int main()
{
  int i,j;
  char s[3][3];
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      cin>>s[i][j];
      if(i==j)
      {
        cout<<s[i][j];
      }
    }
  }
  return 0;
}