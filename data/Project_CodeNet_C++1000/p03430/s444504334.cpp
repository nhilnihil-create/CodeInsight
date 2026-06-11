#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> ii;
typedef vector<pair<ll,ll> > vii;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<pair<long long,long long> > vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

#define PI 3.141592653589793
#define mod 1000000007
#define N 1000000000
//# define N 2003
template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }
# define INF 10000000
# define A 1000000

//bool vis[N+5],vis1[N+5];
string s;
int dp[300][300][300];
int  solve(int l,int r,int k)
{
	if(l==r)
	{
		return 1;
	}
	if(l>r)
	{
		return 0;
	}
	if(dp[l][r][k]!=-1)
		return dp[l][r][k];
	int ans;
	if(s[l]==s[r])
		ans=(2+solve(l+1,r-1,k));
	else
	{
		ans=max(solve(l+1,r,k),solve(l,r-1,k));
		if(k)
		ans=max(ans,2+solve(l+1,r-1,k-1));
	}
	return dp[l][r][k]=ans;
}
int main()
{
	IOS;
	int k;
	cin >> s;
	cin >> k;
    memset(dp,-1,sizeof dp);
	int l=s.length();
	cout << solve(0,l-1,k);
}