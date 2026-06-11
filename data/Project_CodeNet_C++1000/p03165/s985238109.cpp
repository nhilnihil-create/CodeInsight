#pragma GCC optimize("O2")
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<unordered_map>
#include<set>
#include<cmath>
#include<climits>
#include<random>
#include <iomanip>
#include <bitset>
using namespace std;
 
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
 
/////////////////////////////////////////////
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
///////////////////////////////
#define int long long

void solve(){

	string s , t;
	cin>>s>>t;

	int n = s.size();
	int m = t.size();
	int dp[n+1][m + 1];
	memset(dp , 0 , sizeof dp);
	for(int i = 1 ; i <= n ; ++i){
		
		for(int j = 1 ; j <= m ;++j){
			
			if(s[i-1]==t[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
		}
	}

	int len = dp[n][m];
	string ans = "";
	int i = n , j = m;
	while(len){
	
		while(i >=0 && dp[i][j]==len)
			--i;
		while(j >=0 && dp[i+1][j]==len)
			--j;
		ans.push_back(s[i]);
		--len;
	}
	reverse(ans.begin(),ans.end());

	// for(int i = 1 ; i <= n ;++i)
	// 	for(int j = 1 ; j <= m ; ++j)
	// 		cout<<dp[i][j]<<" \n"[j==m];

	cout<<ans<<endl;
	
}

signed main(){
 
	fast;
	int t = 1;
	//cin>>t;
	while(t--)
		solve();
}