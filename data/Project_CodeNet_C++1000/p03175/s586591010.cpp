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

int black[100005] = {} , white[100005] = {};

pair<int , int> solve(int x , int parent , vector<vector<int>> &adj){
	if(black[x] && white[x]){
		return {black[x] , white[x]};
	}
	
	int black_way = 1 , white_way = 1;
	for(int i : adj[x]){
		if(i != parent){
			pair<int , int> ways = solve(i , x , adj);
			int b = ways.F;
			int w = ways.S;
			
			black_way = (black_way*w)%mod;
			white_way = (white_way*((b+w)%mod))%mod;
		}
	}
	
	black[x] = black_way;
	white[x] = white_way;
	
	return {black[x] , white[x]};
}

signed main(){

	 ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> adj(n+1);
	
	for(int i = 0 ; i < n-1 ; i++){
		int x , y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	
	pair<int , int> ans = solve(1 , 0 , adj);
	
	cout << (ans.F + ans.S)%mod;
}









