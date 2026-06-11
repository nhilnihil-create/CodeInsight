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

	int n;
	cin >> n;
	int a[n][n];
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			cin >> a[i][j];
			
	vector<int> dp(1<<n , 0);
	dp[0] = 1;
	
	for(int mask = 0 ; mask < (1<<n)-1 ; mask++){
		int men_married = __builtin_popcount(mask); // gives the number of set bits in mask
		for(int women = 0 ; women < n ; women++){
			if(a[men_married][women] && !(mask & (1 << women))){
				int temp = (mask|(1<<women));
				dp[temp] = (dp[temp] + dp[mask])%mod;
			}
		}
	}
	cout << dp[(1<<n)-1];
	
}








