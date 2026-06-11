# include <bits/stdc++.h>
using namespace std;
# define MOD 1000000007
typedef long long ll;
int dp[3001][3001];
// int solve(int n, string str, int index, int greater){
//     if(index == n-1){
//         if(greater == 0){
//             if(str[index-1] == '>') return 1;
//             else return 0;
//         }else{
//             if(str[index-1] == '>') return 0;
//             else return 1;
//         }
//     }
//     if(dp[index][greater] != -1) return dp[index][greater];
//     int rem = n - index;
//     int smaller = rem - greater;
//     int ans = 0;
//     if(str[index-1] == '>'){
//         if(greater == 0){
//             for(int i=1;i<=smaller;i++){
//                 ans = (ans + solve(n, str, index + 1, smaller - i))%MOD;
//             }
//         }
//         else ans = (MOD + solve(n, str, index, greater - 1) - solve(n, str, index + 1, greater - 1))%MOD;
//     }else if(str[index-1] == '<'){
//         if(greater > 0) ans = (solve(n, str, index, greater - 1) + solve(n, str, index + 1, greater - 1))%MOD;
//     }
//     return dp[index][greater] = ans;
// }
int main(){
	int n;
	string str;
	cin>>n;
	cin>>str;
	dp[n-1][0] = (str[n-2] == '>') ? 1 : 0;
	dp[n-1][1] = (str[n-2] == '<') ? 1 : 0;
	for(int i=n-2;i>=1;i--){
	    int rem = n-i;
	    for(int g=0;g<=rem;g++){
	        int s = rem - g;
	        if(g == 0){
	            dp[i][g] = 0;
	            if(str[i-1] == '>'){
	                for(int j=1;j<=s;j++){
    	                dp[i][g] = (dp[i][g] + dp[i+1][s-j])%MOD;
    	            }
	            }
	        }else{
	            if(str[i-1] == '>'){
	                dp[i][g] = (dp[i][g-1] - dp[i+1][g-1] + MOD)%MOD;
	            }else if(str[i-1] == '<'){
	                dp[i][g] = (dp[i][g-1] + dp[i+1][g-1])%MOD;
	            }
	        }
	    }
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
	    ans = (ans + dp[1][n-i])%MOD;
	}
	cout<<ans;
}