#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define watch(x) cout<<(#x)<<"="<<(x)<<'\n'
#define mset(d,val) memset(d,val,sizeof(d))
#define setp(x) cout<<fixed<<setprecision(x)
#define forn(i,a,b) for(int i=(a);i<(b);i++)
#define fore(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define F first
#define S second
#define pqueue priority_queue
#define fbo find_by_order
#define ook order_of_key
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef long double ld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void amin(ll &a, ll b){ a=min(a,b); }
void amax(ll &a, ll b){ a=max(a,b); }
void YES(){cout<<"YES\n";} void NO(){cout<<"NO\n";}
void SD(int t=0){ cout<<"PASSED "<<t<<endl; }
const ll INF = ll(1e18);
const int MOD = 1e9+7;

ll add(ll a, ll b)
{
	//return a+b;
	a+=b; a%=MOD;
	if(a<0) a+=MOD;
	return a;
}
ll mult(ll a, ll b)
{
	if(a>MOD) a%=MOD;
	if(b>MOD) b%=MOD;
	ll ans=(a*b)%MOD;
	if(ans<0) ans+=MOD;
	return ans;
}

const bool DEBUG = 0;
const int MAXN = 105;
const int MAXK = 100005;

int n,K;
ll a[MAXN];
ll dp[MAXN][MAXK];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin>>n>>K;
	fore(i,1,n) cin>>a[i];
	dp[0][0]=1;
	
	fore(i,1,n)
	{
		fore(j,0,K)
		{
			dp[i][j]=add(dp[i][j], dp[i-1][j]-(j-a[i]-1>=0 ? dp[i-1][j-a[i]-1] : 0LL));
			if(j) dp[i][j]=add(dp[i][j], dp[i][j-1]);
		}
	}
	
	cout<<dp[n][K]<<'\n';
	
	/*fore(i,0,n)
	{
		fore(j,0,K) cout<<dp[i][j]<<" ";
		cout<<'\n';
	}*/
	
	return 0;
}
