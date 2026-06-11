
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 

int it[1000001];
int n;
int ans[1000001];
int dp[1000001][2];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<(1<<n);i++){
		cin>>it[i];
	}
	for(int j=0;j<n;j++){
		for(int k=0;k<(1<<n);k++){
			dp[k][0]=-1e9;
			dp[k][1]=-1e9;
		}
		for(int k=0;k<(1<<n);k++){
			for(int i=0;i<n;i++){
				if((k&(1<<i))){
					dp[k][0]=max(dp[k][0],dp[k-(1<<i)][0]);
					dp[k][1]=max(dp[k][1],dp[k-(1<<i)][1]);
				}
			}
			if(k&(1<<j)){
				dp[k][0]=max(dp[k][0],it[k]);
			}
			else{
				dp[k][1]=max(dp[k][1],it[k]);
			}
			
			
			ans[k]=max(ans[k],dp[k][0]+dp[k][1]);
		}
	}
	int cur=0;
	for(int i=1;i<(1<<n);i++){
		cur=max(cur,ans[i]);
		cout<<cur<<endl;
	}

	









	return 0;
}