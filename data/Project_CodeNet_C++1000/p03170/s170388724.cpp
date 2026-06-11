#include<bits/stdc++.h>
using namespace std;
bool solve(int K,vector<int>& dp,int A[],int n) {
	if(K == 0) {
		return false;
	}
	if(dp[K]) {
		return true;
	}
	for(int i=0;i<n;i++) {
		if(A[i] > K) 
			continue;
		if(!solve(K-A[i],dp,A,n)) {
			return dp[K] = true;
		}
	}
	return false;
}
int main() {
	int n,k;
	cin>>n>>k;
	int ar[n];
	for(int i=0;i<n;i++) {
		cin>>ar[i];
	}
	vector<int> dp(k+1,false);
	if(solve(k,dp,ar,n)) {
		cout<<"First";
	}
	else {
		cout<<"Second";
	}
}