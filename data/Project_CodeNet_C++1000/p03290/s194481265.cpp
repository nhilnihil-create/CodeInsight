#include<bits/stdc++.h>
using namespace std;
int n;
long long INF = 200000;
long long dp[20][200000];
int bonus[20];
int p[20];
long long f(int curr,int score){
	if(score<=0) return 0;
	long long&ret = dp[curr][score];
	if(~ret) return ret;
	if(curr>n) return ret = INF;
	ret = INF;
	for(int i=0; i<p[curr]; i++){
		ret = min(ret,i+f(curr+1,score-i*curr));
	}
	ret = min(ret,p[curr]+f(curr+1,score-curr*p[curr]-bonus[curr]));
	return ret;
}
int main(){
	memset(dp,-1,sizeof(dp));
	int g;
	cin>>n>>g;
	g/=100;
	for(int i=1; i<=n; i++){
		cin>>p[i]>>bonus[i];
		bonus[i]/=100;
	}
	cout<<f(1,g);
}