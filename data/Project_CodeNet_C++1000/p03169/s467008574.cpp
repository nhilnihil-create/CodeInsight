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
const int MOD = 998244353;

const bool DEBUG = 0;
const int MAXN = 305;

int n;
int a[4];
ld dp[MAXN][MAXN][MAXN];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	setp(10);
	
	cin>>n;
	forn(i,0,n)
	{
		int x; cin>>x;
		a[x]++;
	}
	
	dp[0][0][0]=0;
	fore(k,0,n) fore(j,0,n) fore(i,0,n)
	{
		if(i+j+k==0) continue;
		ld tmp=1;
		if(i) tmp+=i*1.0L/n*dp[i-1][j][k];
		if(j) tmp+=j*1.0L/n*dp[i+1][j-1][k];
		if(k) tmp+=k*1.0L/n*dp[i][j+1][k-1];
		dp[i][j][k]=tmp*n/(i+j+k);
	}
	
	cout<<dp[a[1]][a[2]][a[3]]<<'\n';
	
	return 0;
}
