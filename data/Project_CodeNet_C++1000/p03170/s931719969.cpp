#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,K,x,y,p,q;
	cin>>n>>K;
	vector<int>A(n);
	for(int i=0;i<n;i++) cin>>A[i];
	vector<bool>dp(K+1);
	for(int k=1;k<=K;k++){
		for(int i=0;i<n;i++){
			if(A[i]>k) break;
			dp[k]=1-dp[k-A[i]];
			if(dp[k]) break;
		}
	}
	if(dp[K]) cout<<"First";
	else cout<<"Second";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}