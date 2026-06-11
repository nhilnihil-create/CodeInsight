#include<bits/stdc++.h>
using namespace std;
 
const int N = 301;
double dp[N][N][N];
 
int main(){
	int n;	
	cin >> n;
 
	int cnt[4] = {0};
 
	for(int i = 0 ; i < n ; i++){
		int x;
		cin >> x;
		cnt[x]++;
	}
 
	dp[0][0][0] = 0;
 
	for(int three = 0 ; three <= n ; three++){
		for(int two = 0 ; two <= n ; two++){
			for(int one = 0 ; one <= n ; one++){
				int zero = n - three - two - one;
				if (zero == n){
					continue;
				}
				if (one + two + three > n){
					continue;
				}
				double val = 1;
				if(three > 0)val += (1.0 * three/n) * dp[three-1][two+1][one];
				if(two > 0)val += (1.0 * two/n) * dp[three][two-1][one+1];
				if(one > 0)val += (1.0 * one/n) * dp[three][two][one-1];
 
				dp[three][two][one] = val / (1 - 1.0 * zero/n);
			}
		}
	}
 
	cout << setprecision(9) << fixed;
	cout << dp[cnt[3]][cnt[2]][cnt[1]];
 
	return 0;
}