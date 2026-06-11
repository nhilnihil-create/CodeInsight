#include <iostream>
#include <iomanip>

using namespace std;

double dp[3100][1600];

void coin(double* arr,int N ){

	int max_tails = (N-1)/2;
	dp[0][0] = arr[0];
	dp[0][1] = (1-arr[0]);

	for(int tails = 2; tails <= max_tails;tails++)
		dp[0][tails] = 0;

	for(int coins = 1; coins <= N;coins++)
		dp[coins][0] =  arr[coins]*dp[coins-1][0];

	for(int tails=1;tails <= max_tails;tails++)
		for(int coins = 1; coins <= N;coins++)
			dp[coins][tails] = arr[coins]*dp[coins-1][tails] + (1-arr[coins])*dp[coins-1][tails-1];
	
}

int main(){

	int N;
	cin >> N;
	double arr[N];
	for(int i=0;i<N;i++)
		cin >> arr[i];

	coin(arr,N);

	double prob = 0;
	for(int tails=0;tails < (N+1)/2;tails++)
		prob += dp[N-1][tails];

	cout << setprecision(10) << prob << '\n';

	
	return 0;
}