#include<bits/stdc++.h>
#define M 1000000007
#define pb push_back
#define ll long long int
using namespace std;

ll binexp(ll x)
{
	ll res = 1;
	ll y = M-2;
	while(y!=0)
	{
		if(y&1)
		{
			res *= x;
			res %=M;
		}
		x *=x;
		x%=M;
		y=(y>>1);
	}
	return res;
}

int main()
{
	int h,w;
	cin>>h>>w;
	string s[h];
	int i,j;
	for(i = 0;i<h;i++)
		cin>>s[i];
	ll dp[h][w];
	dp[h-1][w-1] = 1;
	for(i=h-1;i>=0;i--)
	{
		for(j=w-1;j>=0;j--)
		{
			if(i==h-1 && j==w-1)
				continue;
			if(s[i][j]=='#')
				dp[i][j] = 0;
			else
			{
				dp[i][j] = 0;
				int x,y;
				x = i+1, y = j;
				if(x<h)
				{
					dp[i][j] += dp[x][y];
					dp[i][j] %= M;
				}
				x = i,y = j+1;
				if(y<w)
				{
					dp[i][j] += dp[x][y];
					dp[i][j] %= M;
				}
			}			
		}
	}
	cout<<dp[0][0];
	return 0;
}
