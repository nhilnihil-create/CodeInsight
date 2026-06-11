#include<bits/stdc++.h>
using namespace std;
#define modul 1000000007

//no of ways to reach ith row and jth column
int dp[1001][1001];


int main()
{
	int H, W;
	cin >> H >> W;
	char arr[H][W];
	for(int i=0; i<H;i++ ){
		for(int j=0;j<W;j++){
			cin >> arr[i][j];			 
		}
	}

	//trivial cases                   //since rows and column in dp[][] are items not indices
	for(int i=0;i<1001;i++)
	{
		dp[0][i]=0;
		dp[i][0]=0;
	}

	//base cases: 
	int flag=0;
	for(int i=0;i<H;i++)
	{
		if(arr[i][0]=='#')             //once you encounter a # on the first column then you cannot
			flag=1;                    //reach any cell below in that column.
		if(flag)
			dp[i+1][1]=0;
		else
			dp[i+1][1]=1;
	}

	flag=0;
	for(int i=0;i<W;i++)
	{
		if(arr[0][i]=='#')				//once you encounter a # on the first row then you cannot 
			flag=1;						//reach any cell to the right of it.
		if(flag)
			dp[1][i+1]=0;
		else
			dp[1][i+1]=1;
	}


	//NOTE due to the constrain by equation (1), i or j cannot be less than 2 hence
	//value dp[1][j] and dp[i][1] are handled by the base case above.
	for(int i=2;i<=H;i++)
	{
		for(int j=2;j<=W;j++)
		{
			if(arr[(i-1)-1][j-1]=='#' && arr[i-1][(j-1)-1]=='#')                 //-(1)
				dp[i][j] = 0;
			else if(arr[(i-1)-1][j-1]=='#' || arr[i-1][(j-1)-1]=='#')
			{
				if(arr[(i-1)-1][j-1]=='#')
					dp[i][j] = dp[i][j-1]; 
				if(arr[i-1][(j-1)-1]=='#')
					dp[i][j] = dp[i-1][j];
			}
			else
				dp[i][j] = (dp[i-1][j]%modul + dp[i][j-1]%modul)%modul;
		}
	}

	cout << dp[H][W];

	return 0;
}