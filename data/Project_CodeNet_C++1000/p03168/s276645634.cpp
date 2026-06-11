// Created by Krishna Ashok
#include <bits/stdc++.h>
using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds; 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Tree;

#define dbg(x) cout<<#x<<"="<<x<<'\n'
#define ll long long
#define pr pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define For(i,n) for(int i=0;i<(n);++i)
#define Forr(i,n) for(int i=n-1;i>=0;i--)
#pragma GCC optimization("Ofast")
#pragma GCC optimization("unroll-loops")
#define fin ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
#define sz(a) (int)a.size()
#define Fill(a,b) memset(a,b,sizeof(a));
#define fileio freopen("http://in.in", "r", stdin),freopen("out.out", "w", stdout);
#define sd(x) scanf("%d",&x)
#define sld(x) scanf("%lld",&x)
const int INF=1e9;

void solve(){
	int n;
	cin>>n;
	vector<double> p(n+1);
	For(i,n)cin>>p[i+1];
	vector<vector<double>> dp(n+1,vector<double>(n+1,0.0));
	dp[0][0]=1.00;
	for(int i=1;i<=n;i++){
		dp[0][i]=dp[0][i-1]*(1-p[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			//i is no of heads in first j coins
			dp[i][j]=dp[i-1][j-1]*p[j]+dp[i][j-1]*(1-p[j]);
		}
	}
	double tot=0.00;
	// for(auto x:dp){
	// 	for(auto i:x)cout<<i<<' ';
	// 	cout<<endl;	
	// }
	for(int i=(n+1)/2;i<=n;i++)tot+=dp[i][n];
	cout<<setprecision(11)<<tot<<endl;	
}



int main()
{
    fin;
    solve();
    return 0;
}