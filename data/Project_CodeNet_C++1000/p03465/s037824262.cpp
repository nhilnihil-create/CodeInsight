#include<bits/stdc++.h>
using namespace std;
bool check[2007][100005];
int a,n;
int main()
{
	cin>>n;
	int sum=0;
	check[0][0]=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		sum+=a;
		for(int j=0;j<=100000;j++)
		{
			if(j+a<=100000) check[i][j+a]|=check[i-1][j];
			check[i][abs(j-a)]|=check[i-1][j];
		}
	}
	for(int i=0;i<=100000;i++)
	{
		if(check[n][i])
		{
			cout<<((sum+i)>>1);
			break;
		}
	}
}