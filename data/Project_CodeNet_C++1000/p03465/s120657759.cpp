#include<bits/stdc++.h>
using namespace std;
const int maxn=2002;
int a[maxn];
bool dp[maxn][100001];
signed main() {
	int n;
	cin>>n;
	int sum=0;
	for(int i=1 ; i<=n ; i++) {
		cin>>a[i];
		sum+=a[i];
	}
	for(int i=0 ; i<=n ; i++) {
		for(int j=0 ; j<=100000 ; j++) {
			dp[i][j]=false;
		}
	}
	dp[1][a[1]]=1;
	for(int i=1 ; i<n ; i++) {
		for(int j=0 ; j<=100000 ; j++) {
			if(dp[i][j]==true) {
				//cout<<"i j "<<i<<" "<<j<<endl;
				if(j>=a[i+1]) {
					dp[i+1][j-a[i+1]]=true;
				}
				else {
					dp[i+1][a[i+1]-j]=true;
				}
				if(j+a[i+1]<=100000) dp[i+1][a[i+1]+j]=true;
			}
		}
	}
	for(int i=0 ; i<=100000 ; i++) {
		if(dp[n][i]) {
			cout<<(sum+i)/2;
			return 0;
		}
	}
}