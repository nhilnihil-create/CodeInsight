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
int a[405];
int dp[405][405] = {} , cost[405][405];

pair<int , int> solve(int l , int r){
	//cout << l << " " << r << endl;
	if(l == r){
		dp[l][r] = a[l];
		cost[l][r] = 0;
		return {dp[l][r] , 0};
	}
	
	if(dp[l][r])
		return {dp[l][r] , cost[l][r]};
	
	int ans = LLONG_MAX;

	for(int i = l ; i < r ; i++){
		int no1 = solve(l , i).F;
		int no2 = solve(i+1 , r).F;
		
		int past_cost = solve(l , i).S + solve(i+1 , r).S;
		
		if(no1 + no2 + past_cost < ans){
			ans = no1 + no2 + past_cost;
			dp[l][r] = no1 + no2;
			cost[l][r] = ans;
		}
	}
	
	return {dp[l][r] , cost[l][r]};
}

signed main(){

	 ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	
	cout << solve(0 , n-1).S;
}








