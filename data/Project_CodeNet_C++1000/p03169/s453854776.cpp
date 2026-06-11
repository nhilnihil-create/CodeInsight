#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

double dp[301][301][301];

double solve(int x,int y,int z,int n)
{
	if(x==0&&y==0&&z==0)
	{
		return(0);
	}
	if(x<0||y<0||z<0)
	{
		return(0);
	}
	if(dp[x][y][z]>-0.9)
	{
		return(dp[x][y][z]);
	}
	double exp=n+x*(solve(x-1,y,z,n))+y*solve(x+1,y-1,z,n)+z*solve(x,y+1,z-1,n);
	return(dp[x][y][z]=exp/(x+y+z));
}
int main()
{
	long long int n,i,j,k;
	cin>>n;
	int x;
	int one=0,two=0,three=0;
	for(i=0;i<n;i++)
	{
		cin>>x;
		if(x==1)
		{
			one++;
		}
		if(x==2)
		{
			two++;
		}
		if(x==3)
		{
			three++;
		}
	}
	for(i=0;i<301;i++)
	{
		for(j=0;j<301;j++)
		{
			for(k=0;k<301;k++)
			{
				dp[i][j][k]=-2.0;
			}
		}
	}
	cout<<fixed<<setprecision(9)<<solve(one,two,three,n);
}


