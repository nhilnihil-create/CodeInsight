#include<bits/stdc++.h>
#define ull unsigned long long int 
#define pb push_back
#define F first
#define S second
#define ll long long 
#define ld long double 

#define int long long int

const int mod = 1e9+7;
const ll inf = 1e18; 
 
int power(int x,int y){int res=1;x=x%mod;while(y>0){if(y&1)res=(res*x)%mod;y=y>>1;x=(x*x)%mod;}return res;}
int ncr(int n, int r){ int C[r+1]; memset(C, 0, sizeof(C)); C[0] = 1; for(int i = 1; i <= n; i++) {int t=i;if(r<t)t=r; for (int j = t; j > 0; j--) C[j] = C[j] + C[j-1]; }return C[r];} 
int gcd(int a,int b){if (a==0)return b;return gcd(b%a,a);}
int lcm(int a,int b){return (a/gcd(a,b)*b);}

int min(int a , int b){return a < b ? a : b;}
int max(int a , int b){return a > b ? a : b;}

using namespace std;


signed main(){

	 ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , k;
	cin >> n >> k;
	int a[n];
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	
	int dp[k+1] = {};
	dp[0] = 1;
	
	for(int i = 0 ; i < n ; i++){
		int prefix_sum[k+1] = {};
		for(int given = 0 ; given <= k ; given++){
			int mini = given + 1;
			int maxi = given + min(a[i] , k-given);
			
			if(mini <= maxi){
				prefix_sum[mini] = (prefix_sum[mini] + dp[given])%mod;
				if(maxi+1 <= k)
					prefix_sum[maxi+1] = (prefix_sum[maxi+1] - dp[given] + mod)%mod;
			}
	
		}
		
		for(int j = 0 ; j <= k ; j++){
			if(j)
				prefix_sum[j] = (prefix_sum[j] + prefix_sum[j-1])%mod;
			dp[j] = (dp[j] + prefix_sum[j])%mod;
		}
	}
	
	cout << dp[k];
}








