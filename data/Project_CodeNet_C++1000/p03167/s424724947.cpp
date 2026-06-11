#include<bits/stdc++.h>

#define int long long

using namespace std;

int row , colum;

const int MOD=1e9+7;

int dp[1005][1005];

char a[1005][1005];

void init()
{
	for(int i=0 ; i<=row ; ++i)
	{
		for(int j=0 ; j<=colum ; ++j)
		{
			dp[i][j]=0;
		}
	}
	for(int i=1 ; i<=colum ; ++i)
	{
		if(a[1][i]=='.')dp[1][i]=1;
		else break;
	}
	for(int i=2; i<=row ; ++i)
	{
		if(a[i][1]=='.')dp[i][1]=1;
		else break;
	}
}

void dynamic()
{
	for(int i=1 ; i <= row ; ++i )
	{
		for(int j=1 ; j <= colum ; ++j )
		{
			if(a[i][j]=='#')continue;
			if(a[i-1][j]=='.'&&a[i][j-1]=='.')dp[i][j]=dp[i-1][j]%MOD+dp[i][j-1]%MOD;
			else if(a[i-1][j]=='.'&&a[i][j-1]=='#')dp[i][j]=dp[i-1][j]%MOD;
			else if(a[i-1][j]=='#'&&a[i][j-1]=='.')dp[i][j]=dp[i][j-1]%MOD;
		}
	}
	cout << dp[row][colum]%MOD<<endl;
}

main()
{
	cin >> row >> colum ;
	for( int i=1 ; i <= row ; ++i)
	{
		for( int j = 1; j<= colum ; ++j )
		{
			cin >> a[i][j];
		}
	}
	init();
	dynamic();
	
}

