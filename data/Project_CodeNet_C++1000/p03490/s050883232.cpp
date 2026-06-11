#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int a[8007];
bool dp[8007][16007];
int main()
{
	string s;
	cin>>s;
	int fx,fy,i,j;
	cin>>fx>>fy;
	int m=0,k=0;
	for(i=0;i<s.size();i++)
	{
		if(s[i]=='T')
		{
			k++;
			a[k]=m;
			m=0;
		}
		else 
			m++;
	}
	k++;
	a[k]=m;
	dp[1][a[1]+8000]=1;
	for(i=3;i<=k;i+=2)
		for(j=0;j<=16000;j++)
		{
			if(j+a[i]<=16000)
				dp[i][j]=dp[i-2][j+a[i]];
			if(j-a[i]>=0)
				dp[i][j]=dp[i][j]||dp[i-2][j-a[i]];
		}
	dp[0][8000]=1;
	for(i=2;i<=k;i+=2)
		for(j=0;j<=16000;j++)
		{
			if(j+a[i]<=16000)
				dp[i][j]=dp[i-2][j+a[i]];
			if(j-a[i]>=0)
				dp[i][j]=dp[i][j]||dp[i-2][j-a[i]];
		}
	int ans;
	if(k%2==0){ 
		ans=dp[k][fy+8000]&&dp[k-1][fx+8000];
	}
	else{
		ans=dp[k][fx+8000]&&dp[k-1][fy+8000];
	}	
	cout<<(ans==0?"No":"Yes");
	return 0;
}