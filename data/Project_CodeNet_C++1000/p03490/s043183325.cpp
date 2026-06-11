#include <iostream>
#include <cstring>

using namespace std;
int a[8005];
bool f[8005][16005];
int j=0;
void findx(int t,int x)
{
	if(f[t][x+8000]) return;
	if(t+2<=j)
	{
		findx(t+2,x+a[t+2]);
		findx(t+2,x-a[t+2]);
	}
	f[t][x+8000]=true; 
}
void findy(int t,int y)
{
	if(f[t][y+8000]) return;
	if(t+2<=j)
	{
		findy(t+2,y+a[t+2]);
		findy(t+2,y-a[t+2]);
	}
	f[t][y+8000]=true; 
}
int main()
{
	memset(f,0,sizeof(f));
	int x,y;string s;
	cin>>s>>x>>y;
	int cnt=0;
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
	a[0]=0;
	findx(1,a[1]);
	findy(0,0);
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