#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <queue>
#include <math.h>
#include <bitset>
#define INF 100000000000
#define N 100001
#define ll long long
using namespace std;

int main() {
	vector<int> A;
	A.push_back(1);
	for(int i = 1; pow(6, i) <= 1000000; i++) {
		A.push_back(pow(6, i));
	}
	for(int i = 1; pow(9, i) <= 1000000; i++) {
		A.push_back(pow(9, i));
	}
	int n;
	cin>>n;
	sort(A.begin(),A.end());
	
	ll dp[n+1];
	dp[0]=0;
	dp[1]=1;
	
	for (ll i=2; i<=n; i++){
	    auto it = lower_bound(A.begin(), A.end(), i+1);

        ll index = it - A.begin() - 1;
        
        if (i>=A[index]){
            dp[i]=min(dp[i-A[index]]+1,dp[i-1]+1);
            dp[i]=min(dp[i],dp[i-A[index-1]]+1);
        }
	}
	
	cout<<dp[n]<<endl;
}