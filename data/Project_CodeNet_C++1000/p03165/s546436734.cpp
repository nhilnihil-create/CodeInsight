#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int maxValue = 1e5 + 5;

int main(){
	string a , b;
	cin>>a>>b;
	int n = a.size() , m = b.size();
	int dp[n + 1][m + 1];
	for(int i = 0; i <= n; i++){
	    for(int j = 0; j <= m; j++){
	        dp[i][j] = 0;
	    }
	}
	for(int i = 1; i <= n; i++){
	    for(int j = 1; j <= m; j++){
	        if(a[i - 1] == b[j - 1]){
	            dp[i][j] = dp[i - 1][j - 1] + 1;
	        }
	        else{
	            dp[i][j] = max(dp[i][j - 1] , dp[i - 1][j]);
	        }
	    }
	}
// 	cout<<dp[n][m]<<endl;;
	int j = m , count = dp[n][m];
	string ans(count , '.');
	for(int i = n; i > 0; i--){
	    j = m;
	    for(;j > 0; j--){
	        if((dp[i - 1][j - 1] == (dp[i][j] - 1)) && (a[i - 1] == b[j - 1]) && (dp[i][j] == count)){
	            ans[count - 1] = b[j - 1];
	            j--;
	            count--;
	            break;
	        }
	    }
	    
	}
	cout<<ans;
}