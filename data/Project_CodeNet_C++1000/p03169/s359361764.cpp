#include<iostream>
#include<vector>

int n;
std::vector<std::vector<std::vector<double>>> dp;

double rec(int i, int j, int k){
	if(dp[i][j][k] >= 0) return dp[i][j][k];
	if(i==0 && j==0 && k==0) return 0.0;

	double res = 0.0;
	if(i>0) res += rec(i-1, j, k) * i;
	if(j>0) res += rec(i+1, j-1, k) * j;
	if(k>0) res += rec(i, j+1, k-1) * k;
	res += n;
	res *= 1.0 / (i + j + k);

	return dp[i][j][k] = res;
}

int main(){
	std::cin >> n;
	int one = 0, two = 0, three = 0;
	for(int i=0; i<n; i++){
		int a;
		std::cin >> a;
		if(a == 1){
			one++;
		}else if(a == 2){
			two++;
		}else{
			three++;
		}
	}

	dp = std::vector<std::vector<std::vector<double>>>\
	(n+1, std::vector<std::vector<double>>(n+1, std::vector<double>(n+1, -1)));

	printf("%.10f \n", rec(one, two, three));
	return 0;
}