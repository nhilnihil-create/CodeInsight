#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ull unsigned ll
#define pb push_back

using namespace std;

double dp[3000][3000];

int main(){
	int n;cin>>n;
	double a[n+1];
	for(int i=1;i<=n;i++)cin>>a[i];
	dp[1][0]=1-a[1];
	dp[1][1]=a[1];
	for(int i=2;i<=n;i++){
		dp[i][0]=dp[i-1][0]*(1-a[i]);
		for(int j=1;j<=i;j++){
			dp[i][j]=dp[i-1][j-1]*a[i]+dp[i-1][j]*(1-a[i]);
		}
	}
	double cnt=0;
	for(int i=(n+1)/2;i<=n;i++){
		cnt+=dp[n][i];
	}
	cout<<fixed<<setprecision(10)<<cnt;
	return 0;
}
