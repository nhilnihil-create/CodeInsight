#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n, k;
	cin>>n>>k;
	
	vector<int> choices(n, 0);
	vector<bool> dp(k+1, false);
	
	dp[0] = false;
	
	for(int i=0; i<n; i++) cin>>choices[i];

	for(int w=0; w<=k; w++){
		for(int choice: choices){
			if(w - choice < 0) continue;
			else{
				dp[w] = dp[w] || !dp[w-choice];
			}
		}
	}
	
	cout<<(dp[k] ? "First" : "Second");
	
	return 0;
}