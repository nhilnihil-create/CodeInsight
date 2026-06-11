#include <iostream>
#include <cstring>
 
using namespace std;
/*
FTFFTFFF
4 2
*/
int f[8001][16001];
int a[8001];      
int main()
{		
	memset(f,0,sizeof(f));
	int x,y;
	string s;
	cin>>s>>x>>y;
	int cnt=0;
	int j=0;
	for(int i=0;i<s.size();i++)
	{ 
		if(s[i]=='F')
		{
			cnt++;
		}
		else
		{
			a[++j]=cnt;
			cnt=0;
		}
	}
	if(cnt!=0) a[++j]=cnt;
	f[0][8000]=1;
	f[1][a[1]+8000]=1;
	for(int i=2;i<=j;i++)
	{
		for(int p=0;p<=16000;p++)
		{
			if(p+a[i]<=16000&&f[i-2][p+a[i]]==1) f[i][p]=1;
			else if(p-a[i]>=0&&f[i-2][p-a[i]]==1) f[i][p]=1;
		} 
	}
	if(j%2==0)
	{
		if(f[j-1][x+8000]==1&&f[j][y+8000]==1) cout<<"Yes";
		else cout<<"No"; 
	}
	else
	{
		if(f[j][x+8000]==1&&f[j-1][y+8000]==1) cout<<"Yes";
		else cout<<"No";
	}
	return 0;
} 