#include <bits/stdc++.h>
#include <iostream>

using namespace std;

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

//Time Complexity = O(N*K) but this can also be solved in O(N) using prefix sums

int dp[100005]; //Max value of N is 10^5
int h[100005]; //Max value of h is 10^5
const int inf = 1e9 + 5;

int main(){
	int N, K;
	cin >> N >> K;
	//int h[N];
	for(int i=1; i<=N; i++){
		cin >> h[i];
		dp[i] = inf;
	}
	dp[1] = 0;
	for(int i=2; i<=N; i++){
		for(int j=i-K; j<= i-1; j++){
			if(j>=1){
				dp[i] = min(dp[i], dp[j]+abs(h[i]-h[j]));
			}
		}
	}
	cout << dp[N] << endl;
}