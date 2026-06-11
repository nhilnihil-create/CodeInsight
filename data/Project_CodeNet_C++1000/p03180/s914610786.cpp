#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll int dp[(1<<16)];
ll int sums[(1<<16)];

ll int calculate(vector< vector<ll int> > &score,ll int mask)
{
	ll int ans=0;
	for(int i=0;i<17;i++)
	{
     for(int j=i+1;j<17;j++)
     {if(  ((mask&(1<<i))!=0) && ((mask&(1<<j))!=0) )
     	ans+=score[i][j];

     }

	}
	return ans;
}
ll preparesums(vector< vector<ll int> > &score,ll int n)
{
for(ll int subset=1;subset<(1<<n);subset++)
{
	sums[subset]=calculate(score,subset);
}	

}

ll solve(vector< vector<ll int> > &score,ll int mask)
{
	if(mask==0)
		return 0;
	if(dp[mask]!=INT_MAX)
		return dp[mask];
	dp[mask]=0;
	for(ll int submask=mask;submask!=0;submask=((submask-1)&mask))
	{
		dp[mask]=max(dp[mask],sums[submask]+solve(score,(mask^submask) ));
	}
	return dp[mask];
}
int main()
{
   
 ll int n;
 cin>>n;
 vector< vector<ll int> > score(n,vector<ll int> (n));
 
for(ll int i=0;i<(1<<n);i++)
	dp[i]=INT_MAX;


 for(ll int i=0;i<n;i++)
 {for(ll int j=0;j<n;j++)
 	cin>>score[i][j];}
 	preparesums(score,n);
 	ll int d=solve(score,((1<<n)-1));
 	cout<<d<<endl;



}