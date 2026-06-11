#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 1e9
// #define MOD 1e9+7

vector<vector<ll> > dp;
vector<vector<int> > arr;
int MOD = 1e9+7;
int main(){
	int m,n;cin>>m>>n;
	dp.resize(m+1,vector<ll>(n+1,0));
	arr.resize(m,vector<int>(n,0));
	for(int i=0;i<m;i++){
		string a;
		cin>>a;
		for(int j=0;j<n;j++){
			if(a[j]=='.') arr[i][j]=1;
		}
	}
	dp[m-1][n-1] = 1;
	for(int i=m-1;i>=0;i--){
		for(int j=n-1;j>=0;j--){
			if(arr[i][j]==0||(i==m-1&&j==n-1)) continue;
			dp[i][j] = dp[i+1][j]%MOD + dp[i][j+1]%MOD; 
		}
	}
	cout<<(dp[0][0]%MOD)<<endl;
}
