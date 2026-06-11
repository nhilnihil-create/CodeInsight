#include <iostream>
#include <stdio.h>
#include <cmath>
#include <climits>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;


const int INF=1e9 + 5;
int main(){
	cin.tie(0);
	int n;
	cin>>n;
	int k;
	cin>>k;
	vector<int>h(n);
	for(int i=0;i<n;i++){
		cin>>h[i];
	}
	vector<int>dp(n,INF);
	dp[0]=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=i+k;j++){
			if(j<n){
				dp[j]=min(dp[j],dp[i]+abs(h[i]-h[j]));
			}
		}
	}
	printf("%d",dp[n-1]);
	return 0;
}
