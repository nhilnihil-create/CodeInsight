#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define watch(x) cout<<(#x)<<"="<<(x)<<'\n'
#define mset(d,val) memset(d,val,sizeof(d))
#define setp(x) cout<<fixed<<setprecision(x)
#define forn(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define F first
#define S second
#define INF ll(1e18)
#define MOD 998244353
#define pqueue priority_queue
#define fbo find_by_order
#define ook order_of_key
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef long double ld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define MAXN 100005

int c[]={0,2,5,5,4,5,6,3,7,6};

int n,m;
bool can[10];
int dp[10005][5005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	mset(dp,-1);
	
	cin>>n>>m;
	forn(i,0,m){ int x; cin>>x; can[x]=1; }
	
	dp[0][0]=0;
	fore(i,1,n){
		forn(j,1,5005){
			for(int k=9;k>=1;k--){
				if(!can[k]) continue;
				if(i-c[k]<0) continue;
				if(dp[i-c[k]][j-1]!=-1){
					dp[i][j]=k;
					break;
				}
			}
		}
	}
	
	int len=0;
	for(int i=5003;i>=0;i--){
		if(dp[n][i]!=-1){ len=i; break; }
	}
	
	int curcost=n;
	while(len){
		int x=dp[curcost][len];
		cout<<x;
		len--;
		curcost-=c[x];
	}
	
	cout<<'\n';
	
	return 0;
}
