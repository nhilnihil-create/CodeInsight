#include<bits/stdc++.h>
using namespace std;
const long long N=1<<19;
long long a[N];
long long n,pp;
struct re{
	long long num;
	long long id;
}x[5],dp[N][2];
long long maxer;
short p[N];
bool cmp(re x,re y){return x.num<y.num;}
int main()
{	

	ios::sync_with_stdio(0);
	cin>>n;
	pp=(1<<n)-1;
	for(long long i=0;i<=pp;i++){
	long long c;
	cin>>a[i];
	dp[i][0].num=a[i];
	dp[i][0].id=i;
	dp[i][1].id=-100;
	}
	for(long long i=1;i<pp;i++){
		for(long long j=0;j<n;j++)if((1<<j)&i){
		long long k=(1<<j)^i;
		x[1]=dp[k][0];
		x[2]=dp[k][1];
		x[3].num=a[i];
		x[4].num=a[1<<j];
		x[3].id=i;
		x[4].id=1<<j;
		sort(x+1,x+1+4,cmp);
		int az=0,s;
		for(int l=4;l>=1;l--)
			if(x[l].num>dp[i][0].num){
			az=1;
			re ax=dp[i][0];
			dp[i][0]=x[l];
			x[l]=ax;
			break;}
		for(int l=4;l>=1;l--)
			if(x[l].num>dp[i][1].num&&dp[i][0].id!=x[l].id)
			{dp[i][1]=x[l];}	
		}
		maxer=max(maxer,dp[i][1].num+dp[i][0].num);
		cout<<maxer<<endl;
	}
	long long i=pp;
	for(long long j=0;j<n;j++)if((1<<j)&i){
		long long k=(1<<j)^i;
		x[1]=dp[k][0];
		x[2]=dp[k][1];
		x[3].num=a[i];
		x[4].num=a[1<<j];
		x[3].id=i;
		x[4].id=1<<j;
		sort(x+1,x+1+4,cmp);
		int az=0,s;
		for(int l=4;l>=1;l--)
			if(x[l].num>dp[i][0].num){
			az=1;
			re ax=dp[i][0];
			dp[i][0]=x[l];
			x[l]=ax;
			break;}
		for(int l=4;l>=1;l--)
			if(x[l].num>dp[i][1].num&&dp[i][0].id!=x[l].id)
			{dp[i][1]=x[l];}	
		}
		maxer=max(maxer,dp[i][1].num+dp[i][0].num);
		cout<<maxer<<endl;
	return 0;
}