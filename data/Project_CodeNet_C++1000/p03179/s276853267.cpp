#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int n;
char c[3005];
const int mod=1e9+7;
int main() {
    vector<vector<int>>dp(3005,vector<int>(3005));
    vector<vector<int>>p(3005,vector<int>(3005));
	scanf("%d %s",&n,c);
	dp[1][1]=1;
	for(int len=2;len<=n;len+=1){
	    for(int b=1;b<len;b+=1){
	        p[len-1][b]=(p[len-1][b-1]+dp[len-1][b])%mod;
	    }
	    for(int b=1;b<=len;b+=1){
	        int l,r;
	        if(c[len-2]=='<'){
	            l=1,r=b-1;
	        }
	        else{
	            l=b,r=len-1;
	        }
	        if(l<=r){
	            dp[len][b]=(dp[len][b]+p[len-1][r]-p[len-1][l-1]+mod)%mod;
	        }
	     }
	}
	int ans=0;
	for(int i=1;i<=n;i+=1){
	    ans=(ans+dp[n][i])%mod;
	}
	printf("%d",ans);
	return 0;
}
