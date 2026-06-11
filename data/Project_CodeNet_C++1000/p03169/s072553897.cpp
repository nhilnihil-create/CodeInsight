#include<bits/stdc++.h>
using namespace std;
const int N = 3e2+3;
double dp[N][N][N];
int arr[4], n;
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i){
		int num;
		cin >> num;
		++arr[num];
	}
	for(int three = 0; three <= arr[3]; ++three){
		for(int two = 0; two <= (arr[2]+ arr[3]); ++two){
			for(int one = 0; one <= (arr[1] + arr[2] + arr[3]); ++one){
				int take = one + two + three;
				if(take)
					dp[one][two][three] += ((double)n) / ((double)take);
				if(one)
					dp[one][two][three] += dp[one-1][two][three] * ((double)one) / ((double)take);
				if(two)
					dp[one][two][three] += dp[one+1][two-1][three] * ((double)two) / ((double)take);;
				if(three)
					dp[one][two][three] += dp[one][two+1][three-1] * ((double)three) / ((double)take);;
			}
		}
	}
	cout << setprecision(20) << dp[arr[1]][arr[2]][arr[3]];
	return 0;
}
