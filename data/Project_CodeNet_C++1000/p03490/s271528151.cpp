#include <bits/stdc++.h>

using namespace std;

bool dp[4001][16001];
int x,y;
string s;
int ax[4001],ay[4001];
int tx,ty;

void dfsx(int t,int n){
	if (dp[t][8000+n])return ;
	if (t<tx){
		dfsx(t+1,n+ax[t]);
		dfsx(t+1,n-ax[t]);
	}
	
	dp[t][n+8000]=1;
}

void dfsy(int t,int n){
	if (dp[t][8000+n])return ;
	if (t<ty){
		dfsy(t+1,n+ay[t]);
		dfsy(t+1,n-ay[t]);
	}
	
	dp[t][n+8000]=1;
}

int main()
{
	cin>>s;
	cin>>x>>y;
	int i,j;
	bool fx=1;
	for (i=0;i<s.size();i++){
		if (s[i]=='F'){
			if (fx)ax[tx]++;
			else ay[ty]++;
		}
		else{
			if (fx)fx=0,tx++;
			else fx=1,ty++;
		}
	}
	if (s[s.size()-1]=='F'){
		if (fx)tx++;
		else ty++;
	}
	dfsx(1,ax[0]);
	bool xx=dp[tx][8000+x];
	
	memset(dp,0,sizeof(dp));
	dfsy(0,0);
	bool yy=dp[ty][8000+y];
	
	if (xx && yy){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	return 0;
}