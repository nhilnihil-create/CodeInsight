#include <bits/stdc++.h>
using namespace std;
#define F(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;
#define mod 1000000007
int main()
{	
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int w=1;
	// cin>>w;
	while(w--){
		int n;
		cin>>n;
		int arr[n][3];
		// cin>>arr[0][0]>>arr[0][1]>>arr[0][2];
		for(int i=0;i<n;i++){
			cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
		}
		int dp[n][3];
		dp[0][0]=max(arr[0][1],arr[0][2]);
		dp[0][2]=max(arr[0][0],arr[0][1]);
		dp[0][1]=max(arr[0][0],arr[0][2]);
		F(i,1,n){
			dp[i][0]=max(dp[i-1][1],dp[i-1][2])+arr[i][0];
			dp[i][1]=max(dp[i-1][0],dp[i-1][2])+arr[i][1];
			dp[i][2]=max(dp[i-1][0],dp[i-1][1])+arr[i][2];
		}
		cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));

	}
}