#include <bits/stdc++.h>
#include <iostream>

using namespace std;
//State
//dp[i][j]: The maximum value we can get by using blocks from
// 0...i and sum of blocks in the tower = j

//Initialization
//dp[0][W[0]] = V[0]

//Transitions
//dp[i][j] = max(V[j]+dp[i-W[0]][j-1], dp[i][j-1])

//Order of evaluation
//Rowise or Columnwise

//Answer: argmax(dp[0...W_max][N])

struct B{
	long long w;
	long long s;
	long long v;
};

vector<vector<long long>> dp(20004,vector<long long>(1004,0));

bool compare(B b1, B b2){
	return (b1.w+b1.s<=b2.w+b2.s);
}

int main(){
	long long N;
	cin >> N;
	vector<B> boxes(N);
	for(long long i=0; i<N; i++){
	    long long w, s, v;
		cin >> w >> s >> v;
		boxes[i].w = w;
		boxes[i].s = s;
		boxes[i].v = v;
	}
	sort(boxes.begin(), boxes.end(), compare);
	long long W_max = 20004;
	dp[boxes[0].w][0] = boxes[0].v;
	for(int i=0; i<W_max; i++){
	    if(i>=boxes[0].w){
	        dp[i][0] = boxes[0].v;
	    }
	}
	for(long long j=1; j<N; j++){
		for(long long i=0; i<W_max; i++){
			if(i-boxes[j].w>=0 && boxes[j].s+boxes[j].w-i>=0){
				dp[i][j] = max(dp[i-boxes[j].w][j-1]+boxes[j].v, dp[i][j-1]);
			}
			else{
				dp[i][j] = dp[i][j-1];
			}
		}
	}
	long long result = 0;
	for(long long i=0; i<W_max; i++){
	    if(result<dp[i][N-1]) result = dp[i][N-1];
	}
	cout << result << endl;
}





