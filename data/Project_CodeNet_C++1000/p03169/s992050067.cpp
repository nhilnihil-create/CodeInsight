#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 301
double dp[N][N][N];

void init()
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			for(int k=0;k<N;k++)
				dp[i][j][k]=-1;
}

double fun(int a,int b,int c,int n)
{
	if(a==0 && b==0 && c==0)
		return 0;
	if(dp[a][b][c]!=-1)
		return dp[a][b][c];

	double res=((double)n)/(a+b+c);
	if(a>0)
	{
		res+=fun(a-1,b,c,n)*((double)a/(a+b+c));
	}	
	if(b>0)
	{
		res+=fun(a+1,b-1,c,n)*((double)b/(a+b+c));
	}
	if(c>0)
	{
		res+=fun(a,b+1,c-1,n)*((double)c/(a+b+c));
	}
	dp[a][b][c]=res;

	return dp[a][b][c];
}

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 

	init();

	int n;
	cin>>n;

	int a=0,b=0,c=0;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(x==1)
			a++;
		else if(x==2)
			b++;
		else
			c++;
	}
	double ans=fun(a,b,c,n);
	cout<<setprecision(15)<<ans;
}