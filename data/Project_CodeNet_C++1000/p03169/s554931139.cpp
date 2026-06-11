#include <bits/stdc++.h>
using namespace std;
double N,blank = -1;
double arr[5];
int cnt[5]={0};
double dp[302][302][302];
double call(){
	int i,j=0;
	if(cnt[0]==N)	return 0;
	if(dp[cnt[1]][cnt[2]][cnt[3]]!=blank)
		return dp[cnt[1]][cnt[2]][cnt[3]];

	double p =cnt[0];
	double d = N/(N-p);
	for(i=1;i<=3;i++){
		if(cnt[i]==0)
			continue;
		cnt[i]-=1;
		cnt[i-1]+=1;
		j++;
		d+=call()*(cnt[i]+1)/(N-p);
		cnt[i]+=1;
		cnt[i-1]-=1;
	}
	return dp[cnt[1]][cnt[2]][cnt[3]]=d;
}

int main()
{
	
	cin>>N;
	int n;
	for(int i=0;i<=300;i++)
		for(int j=0;j<=300;j++)
			for(int k=0;k<=300;k++)
				dp[i][j][k]= -1;

	for(int i=0;i<N;i++){
		cin>>n;
		cnt[n]+=1;
	}
	cout<<setprecision(12) << call();
	return 0;
}