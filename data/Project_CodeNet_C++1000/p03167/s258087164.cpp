#include <iostream>
using namespace std;
int main()
{
  int h,w;
  cin>>h>>w;
  char a[h][w];
  int n[h][w];
  for(int i=0;i<h;i++)
  {
  	for(int j=0;j<w;j++)
  	{
  		a[i][j]=' ';
  		n[i][j]=0;
	  }
  }
  for(int i=0;i<h;i++)
  {
    for(int j=0;j<w;j++)
    {
      cin>>a[i][j];
    }
  }
  for(int i=0;i<h;i++)
  {
  	for(int j=0;j<w;j++)
  	{
  		if(a[i][j]=='#')
  		n[i][j]=0;
  		else
  		{
        if(i==0)
        {
        	if(j==0)
        	n[i][j]=1;
        	else
        	n[i][j]=n[i][j-1];
		}
		else
		{
			if(j==0)
			n[i][j]=n[i-1][j];
			else
			n[i][j]=(n[i][j-1]+n[i-1][j])%1000000007;
		}
	   }
	}
  }
  int x=n[h-1][w-1];
  cout<<x;
}