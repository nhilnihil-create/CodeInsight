#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 340
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll mod=1000000007;
const ll inf=1e18;
const ld pai=acos(-1);
ll n;
string s;
ll dp[3009][3009];
ll sum[3009][3009];
int main(){
	cin>>n>>s;
	s=' '+s;
	dp[0][1]=1;
	for(ll i=1;i<=n;i++)sum[0][i]=1;
	for(ll i=1;i<s.size();i++){
		for(ll j=1;j<=i+1;j++){
			if(s[i]=='>')dp[i][j]=sum[i-1][n]-sum[i-1][j-1]+mod;
			else dp[i][j]=sum[i-1][j-1];
			dp[i][j]%=mod;
		}
		for(ll j=1;j<=n;j++)sum[i][j]=dp[i][j]+sum[i][j-1],sum[i][j]%=mod;
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)ans+=dp[n-1][i],ans%=mod;
	cout<<ans<<endl;
}
