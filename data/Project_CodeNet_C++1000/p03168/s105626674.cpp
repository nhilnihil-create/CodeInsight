#include <iostream>
#include <vector>
#include <iomanip>  
using namespace std;

int main() {
	// your code goes here
	int N = 0;
	cin>>N;
	vector<vector<double>> dp(N, vector<double>(N, 0));
	vector<double> prob;
	for(int i=0;i<N;i++){
		double val;
		cin>>val;
		prob.push_back(val);
	}
	//dp[i][j] i - number of coins j is the total number of tails till now.
	dp[0][0] = prob[0]; //P0
	dp[0][1] = 1 - prob[0];// P0`
	for(int i=1;i<N;i++){
		double pos = prob[i];
		double neg = 1 - prob[i];
		for(int j=0;j<N;j++){
			dp[i][j] += dp[i-1][j] * pos;
			if(j<N-1)dp[i][j+1] += dp[i-1][j] * neg;
		}
	}
	double result=0;
	for(int i=0;i<=N/2;i++)result+= dp[N-1][i];
	cout<<setprecision(10)<<result;
	return 0;
}