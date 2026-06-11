#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iomanip>
#include<cstring>
#define initdp(a,b) for(int i=0;i<=a;i++)for(int j=0;j<=b;j++)dp[i][j]=-1;
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define rep(i,n) for(int i=0;i<n;i++)
#define repd(i,n) for(int i=n-1;i>=0;i--)
#define waste ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define inf 1e9+1
#define inf1 1e18+1
#define mod 1000000007
#define pie 3.14159265358979323846
#define N 1005
#define mid(l,r) l+(r-l)/2
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int ddx[8]={1,1,0,-1,-1,-1,0,1},ddy[8]={0,1,1,1,0,-1,-1,-1};
void mad(ll &a,ll b){a=(a+b)%mod;if(a<0)a+=mod;}
ll gcd(ll a,ll b){ if(a>b)swap(a,b);if(!a)return b;return gcd(b%a,a);}
ll n,w[N],s[N],v[N];
ll dp[N][10005];
int id[N];
ll maxi=-inf;
ll rec(int ii,ll wt){
	int i=id[ii];
	if(ii==n)return 0;
  	if(wt>maxi)return 0;
	if(dp[i][wt]!=-1)return dp[i][wt];
	if(wt<=s[i])dp[i][wt]=rec(ii+1,wt+w[i])+v[i];
	dp[i][wt]=max(dp[i][wt],rec(ii+1,wt));
	return dp[i][wt];
}
bool fun(int i,int j){
	if(s[i]+w[i]==s[j]+w[j])return v[i]>v[j];
	return s[i]+w[i]<s[j]+w[j];
}
void solve(){
	cin>>n;
	rep(i,n){cin>>w[i]>>s[i]>>v[i];maxi=max(maxi,s[i]);}
  	initdp(n,maxi);
	rep(i,n)id[i]=i;
	sort(id,id+n,fun);
	cout<<rec(0,0);
}
int main()
{
	waste;
	int t;
	//cin>>t;
	t=1;
	while(t--){
		solve();
	}
}