#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;cin>>n;
	int a[n][n];
	int M=1e9+7;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
	int dp[1<<n]={0};
	dp[0]=1;
	for(int i=0;i<1<<n;i++){
	//	cout<<"kneffkl "<<i<<endl;
		int x=__builtin_popcount(i);
		for(int j=0;j<n;j++){
			if(a[x][j]==1 && !(i&1<<j)){
				int m2=i^1<<j;
				
				dp[m2]+=dp[i];
				dp[m2]%=M;
				//cout<<i<<" "<<m2<<" "<<dp[m2]<<endl;
				
			}
		}
	}
	
	int m=1<<n;
	m--;
	
	cout<<dp[m]<<endl;
	
	return 0;
}