#include <iostream>
#include <vector>

int main(){
	int n;
	std::cin >> n;
	std::vector<int> co(200000,0),dp(n,0),da(n);
	int c;
	std::cin >> c;
	da[0]=c;
	dp[0]=1;
	co[c-1]=1;
	for(int i=1;i<n;i++){
		std::cin >> c;
		da[i]=c;
		dp[i]=dp[i-1];
		if(da[i]!=da[i-1]){
			dp[i]=(co[c-1]+dp[i])%1000000007;
			co[c-1]=(dp[i-1]+co[c-1])%1000000007;
		}
	}
	std::cout << dp[n-1] << std::endl;
}