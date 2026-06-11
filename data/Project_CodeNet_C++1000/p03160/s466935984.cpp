#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//State
//dp[i] The minimum cost to reach the i-th step from 1st step

//Initialization
//dp[1] = 0, dp[2] = abs(h[1] - h[0])

//Transitions
//dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]),	dp[i-2]+abs(h[i]-h[i-2]))

//Order of evaluation
// i = 1...N

//Answer
//return dp[N]

int dp[100005]; //Max value of N is 10^5
int h[100005]; //Max value of h is 10^5

int main(){
	int N;
	cin >> N;
	int h[N];
	for(int i=1; i<=N; i++){
		cin >> h[i];
	}
	dp[1] = 0;
	dp[2] = abs(h[1]-h[2]);
	for(int i=3; i<=N; i++){
		dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]));
	}
	cout << dp[N] << endl;
}