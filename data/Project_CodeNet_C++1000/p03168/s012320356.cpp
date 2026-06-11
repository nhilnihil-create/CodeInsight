#include<bits/stdc++.h>

using namespace std;
double a[4000], dp[4000][4000];
int vis[4000][4000];
int j;
double rec(int n,int h)
{
	
	if(n==0 && 2*h >=j)
	return 1;
	
	else if(n==0)
	return 0;
	
	
	else
{

    if(vis[n][h]==-1)
    {

    vis[n][h]=1;	
	return dp[n][h]= a[n-1]*rec(n-1,h+1) +(1-a[n-1])*rec(n-1,h);
	
}
	else
	return dp[n][h];
	
	
}
	
	
	
	
}



int main()
{
	int t;
   t=1;
	while(t--)
	{
	
	cin>>j;
	memset(vis,-1,sizeof(vis));
	int i;
	
	for(i=0;i<j;i++)
	cin>>a[i];
	
	
//	cout<<"ddddddddd";
	
	double ans=rec(j,0);
	
	
	printf("%.10lf\n",ans);
	
	
	
	
	}



}
