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
const int MAXN = 3005;

string s,t;
int n,m;
int dp[MAXN][MAXN];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin>>s>>t;
	n=s.length(), m=t.length();
	fore(i,0,n) fore(j,0,m)
	{
		if(i && j && s[i-1]==t[j-1]) dp[i][j]=max(dp[i][j], dp[i-1][j-1]+1);
		if(i) dp[i][j]=max(dp[i][j], dp[i-1][j]);
		if(j) dp[i][j]=max(dp[i][j], dp[i][j-1]);
	}
	string ans;
	int i=n, j=m;
	while(i && j)
	{
		if(s[i-1]==t[j-1])
		{
			ans+=s[i-1]; i--; j--;
		}
		else if(dp[i-1][j]>dp[i][j-1]) i--;
		else j--;
	}
	
	reverse(ans.begin(), ans.end());
	cout<<ans<<'\n';
	
	return 0;
}
