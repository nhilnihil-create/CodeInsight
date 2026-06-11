#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 1e9

// dp[i] player who moves at this wins or not
bool dp[(int)(1e5+1)];
bool vis[(int)(1e5+1)];
int a[100];
int n,k;
int top(int i){
	// cout<<i<<endl;
	// if(i==0) return 0;
	if(i<a[0]) return 0;
	if(vis[i]) return dp[i];
	for(int j=0;j<n;j++){
		if(a[j]>i) break;
		if(!top(i - a[j])) {vis[i]=1;return dp[i] = 1;}
	}
	vis[i]=1;
	return dp[i] = 0;
}

int main(){
	memset(dp,0,sizeof(dp));
	memset(vis,0,sizeof(dp));
	cin>>n;cin>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	// cout<<"continue::"<<endl;
	string ans = top(k)?"First":"Second";
	cout<<ans<<endl;
}