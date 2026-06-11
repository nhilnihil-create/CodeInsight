#include<bits/stdc++.h>
using namespace std;
int n;
const int INF = numeric_limits<int>::max();
int activity[100005][3];
int dp[100005][3];

int main(){
	cin>>n;
	for(int i=1; i<=n; i++){
		for(int j=0; j<3; j++) cin>>activity[i][j];
	}
	//dp[i][j] = i번째 날에 j활동으로 끝낼 때 최대 행복
	dp[1][0] = activity[1][0];
	dp[1][1] = activity[1][1];
	dp[1][2] = activity[1][2];
	for(int i=1; i<=n; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				if(j!=k) dp[i+1][k] = max(dp[i+1][k],dp[i][j]+activity[i+1][k]);
			}
		}
	}
	cout<<max(dp[n][0],max(dp[n][1],dp[n][2])); 
}