#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<P,int> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int n,m;
string s;
vvi dp;

int main(){
	cin>>s>>m;
	n=s.size();
	dp=vvi(n+2,vi(n+2));
	for(int d=0;d<n;d++) for(int l=0;l<n;l++) if(l+d<n){
		int r=l+d;
		if(s[l]==s[r]) dp[l+1][r+1]=dp[l+2][r]+(l==r?1:2);
		dp[l+1][r+1]=max({dp[l+1][r+1],dp[l+2][r+1],dp[l+1][r]});
	}
	for(int i=0;i<m;i++){
		vvi DP(n+2,vi(n+2));
		for(int d=0;d<n;d++) for(int l=0;l<n;l++) if(l+d<n){
			int r=l+d;
			bool B=s[l]==s[r];
			DP[l+1][r+1]=(B?DP[l+2][r]:dp[l+2][r])+(l==r?1:2);
			DP[l+1][r+1]=max({DP[l+1][r+1],DP[l+2][r+1],DP[l+1][r]});
		}
		dp=DP;
	}
	cout<<dp[1][n]<<endl;
}