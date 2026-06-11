#include <bits/stdc++.h>
using namespace std;
int main()
{
	int h,w;
	cin>>h>>w;
	int i,j,x=0,d[h][w];
	char s[h][w];
	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		{
			cin>>s[i][j];
		}
	}
	
	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		{
			x=0;
			if(s[i][j]!='#')
			{
				if((j+1>=0 && j+1<w) && s[i][j+1]=='#')
				{
					x++;
				}
				if((j-1>=0 && j-1<w) && s[i][j-1]=='#')
				{
					x++;				
				}
				if((i+1>=0 && i+1<h) && s[i+1][j]=='#')
				{
					x++;				
				}
				if((i+1>=0 && i+1<h && j-1>=0 && j-1<w) && s[i+1][j-1]=='#')
				{
					x++;				
				}
				if((i+1>=0 && i+1<h && j+1>=0 && j+1<w) && s[i+1][j+1]=='#')
				{
					x++;				
				}
				if((i-1>=0 && i-1<h) && s[i-1][j]=='#')
				{
					x++;				
				}
				if((i-1>=0 && i-1<h && j-1>=0 && j-1<w) && s[i-1][j-1]=='#')
				{
					x++;				
				}
				if((i-1>=0 && i-1<h && j+1>=0 && j+1<w) && s[i-1][j+1]=='#')
				{
					x++;				
				}
			
				d[i][j]=x;		
			}					
		}
	
	}
	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		{
			if(s[i][j]=='.')
			{
				cout<<d[i][j];
				
			}
			if(s[i][j]=='#')
			{
				cout<<s[i][j];
			}
		}
		cout<<endl;
	}
	
	
}