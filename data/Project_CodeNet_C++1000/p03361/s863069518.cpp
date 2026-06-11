#include <bits/stdc++.h>
using namespace std;
int main()
{
	int h,w,i,j,x=0,y=0;
	cin>>h>>w;
	char s[h][w];
	int a[h][w]={0};
	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		{
			cin>>s[i][j];
			if(s[i][j]=='#')
			{
				x++;
			}
		}
	}
	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		{
			if(s[i][j]=='#')
			{
			   if(s[i-1][j]=='#' && i-1>=0)
				{
					a[i][j]=1;	
				}
				if(s[i+1][j]=='#' && i+1<h)
				{
					a[i][j]=1;
				}
				if(s[i][j-1]=='#' && j-1>=0)
				{
					a[i][j]=1;		
				}		
				if(s[i][j+1]=='#' && j+1<w)
				{
					a[i][j]=1;
				}
			}
			
		}
	}
	
	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		{
			if(s[i][j]=='#' && a[i][j]==1)
			{
				y++;
			}
		}
	}
	if(x==y)
	{
		cout<<"Yes"<<endl;
		
	}
	else
	{
		cout<<"No"<<endl;
	}
}