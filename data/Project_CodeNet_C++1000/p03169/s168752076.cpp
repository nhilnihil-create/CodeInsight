#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 1e9
//dp[i][j] - till i, j heads probab
//dp[][][] - expected no. of ops for a,b,c to get over
double dp[305][305][305];
// bool vis[305][305][305];
double N;
double top(int a,int b,int c){
	// cout<<dp[a][b][c];
	if(a<0||b<0||c<0) return 0;
	if(a==0&&b==0&&c==0) return 0;
	if(dp[a][b][c]!=-1) return dp[a][b][c];
	// cout<<a<<b<<c<<endl;
	double eva = top(a-1,b,c);
	double evb = top(a+1,b-1,c);
	double evc = top(a,b+1,c-1);
	double sum = (a+b+c);
	double ans =(N + eva*a + evb*b + evc*c)/sum;
	return dp[a][b][c] = ans;
}
int main(){
	// memset(dp,-1,sizeof(dp));
	int n;cin>>n;
	N=n;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)
				dp[i][j][k]=-1;
	int k;
	int a=0,b=0,c=0;
	for(int i=0;i<n;i++){
		cin>>k;
		if(k==1) a++;
		else if(k==2) b++;
		else c++;
	}
	printf("%.10lf\n", top(a,b,c)); 
	// cout<<top(a,b,c)<<endl;
}