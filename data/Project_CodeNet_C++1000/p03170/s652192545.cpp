#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//State
//dp[i]: The win or lose state of Player-1 when there 
//are only i stones in pile

//Intialization
//dp[0] = 0 (Lose) and dp[1..N] = 0

//Transitions
//if dp[i-a[k]]=0 then dp[i]=1 for some k E [0,N-1]

//Answer
//dp[K][N-1]

int main(){
	int N, K;
	cin >> N >> K;
	vector<int> dp(K+1, 0);
	vector<int> a(N);
	for(int i=0; i<N; i++){
		cin >> a[i];
	}
	
	dp[0] = 0;
	for(int i=1; i<=K; i++){
		for(int j=0; j<N; j++){
			if(a[j]<=i && dp[i-a[j]]==0){
				dp[i] = 1;
				break;
			}
		}
	}
	
	if(dp[K]==1) cout << "First" << endl;
	else cout << "Second" << endl;

}

