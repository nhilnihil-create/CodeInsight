#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3005;
const int MOD = 1e9 + 7;
// dp[i][j] – Number of ways that you can arrange the first i elements with the last element being j 
int dp[MAXN][MAXN], sums[MAXN], n;
string s;

void add_self(int &a, int b){
	a += b;
	if(a >= MOD){
		a -= MOD;
	}
}

int main(){
	cin >>  n >> s;
	dp[1][1] = 1;
	for(int N = 2; N <= n; ++N){
		// Creating prefix sums of dp[N - 1]
		sums[0] = 0;
		for(int i = 1; i < N; ++i){
		    sums[i] = dp[N - 1][i];
		}
		
		for(int i = 1; i <= N; ++i){
		    add_self(sums[i], sums[i - 1]);    
		  //  cout << sums[i] << "\t";
		}
// 		cout << "\n";
		
		char a = s[N - 2];
		for(int last_val = 1; last_val <= N;  ++last_val){
			if(a == '<'){
			    dp[N][last_val] = sums[last_val - 1];
				// for(int prev_val = 1; prev_val < last_val; ++prev_val){
				//     add_self(dp[N][last_val], dp[N - 1][prev_val]);
				// }
			}else if(a == '>'){
				dp[N][last_val] = sums[N - 1] - sums[last_val - 1];
				if(dp[N][last_val] < 0){
				    dp[N][last_val] += MOD;
				}
				// for(int prev_val = last_val + 1; prev_val <= N; ++prev_val){
			 //   	add_self(dp[N][last_val], dp[N - 1][prev_val - 1]);
				// }  
			}
		} 
		
// 		for(int i = 1; i <= N; ++i){
// 		    cout << dp[N][i] << "\t";
// 		}
// 		cout << "\n";
	}
        
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        add_self(ans, dp[n][i]);
    }
    cout << ans << "\n";
	return 0;
}
