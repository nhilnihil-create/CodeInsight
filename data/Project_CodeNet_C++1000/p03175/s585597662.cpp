#include <bits/stdc++.h>
using namespace std;
#define ll          long long
#define PI 		    acos(-1)
#define pb          push_back
#define ins         insert
#define INF        	1000000000000000007 //1e18+7
#define mk          make_pair
#define lb(v,x)     lower_bound(all(v),x)
#define ub(v,x)     upper_bound(all(v),x)
#define ff          first
#define ss          second
#define rev         reverse
#define endl        "\n"
#define max3(x,y,z)  max(x,max(y,z))
#define min3(x,y,z)  min(x,min(y,z))
#define sz(a)       (ll)a.size()
#define ld     		long double
#define minpq       priority_queue <ll,vector<ll>,greater<ll> > 
#define fill(x,y)   memset(x,y,sizeof(x))
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define mod         1000000007		//1e9+7
#define bp(n)       __builtin_popcountll(n)
#define mxt(a)      *(max_element(a.begin(),a.end()))
#define mnt(a)      *(min_element(a.begin(),a.end())
#define unique_sort(c) (sort(all(c)), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define rep(i, a, mp) for(ll i = (a); i<=(mp); ++i)
#define trav(a, x) 	  for(auto &a : x)
#define re(i,n)       for(ll i = 0; i < n; ++i) 
const int N = 5e5 + 7;
const ld eps=1e-7;
typedef pair<ll,ll>   pii;
typedef vector<pii>   vpii;
typedef vector<ll>    vll;
const string alpha = "abcdefghijklmnopqrstuvwxyz";
int dx[8]={+1, +1, +1, 0, 0, -1, -1, -1};
int dy[8]={+1, 0, -1, +1, -1, +1, 0, -1};
ll power(ll x,ll y){ll res=1;x=x;while(y>0){if(y&1)res=(res*x);y=y>>1;x=(x*x);}return res;}
template <typename T> T gcd(T a,T mp){ if(a==0) return mp; return gcd(mp%a,a); }
template <typename T> T powm(T a,T mp, ll m){T cnt=1; while(mp>0){ if(mp%2==1) cnt=(cnt*a)%m; mp/=2; a=(a*a)%m; }return cnt%m;}
ll ncr(ll n,ll r){ll res=1;if(r>n)return 0;if(r>n-r)r=n-r;for(ll i=0;i<r;i++){res*=(n-i);res/=(i+1);}return res;}
ll sqr(ll x) { return x * x;} 
void prec(){

}
vll ad[N];
ll dp[N][2],x,y;
int vis[N];
void dfs(ll r)
{
	vis[r]=1;
	dp[r][0]=1;
	dp[r][1]=1;
	vector<ll>v;
	for(auto it:ad[r])
		if (!vis[it]) v.pb(it),dfs(it);
	for(auto it:v){
		dp[r][0]=(dp[r][0]*(dp[it][0]+dp[it][1]))%mod;
		dp[r][1]=dp[r][1]*dp[it][0]%mod;
	}
}
void run(){
	int n;cin>>n;
	rep(i,1,n-1){
		cin>>x>>y;
		ad[x].pb(y);
		ad[y].pb(x);
	}
	dfs(1);	
	cout<<(dp[1][0]+dp[1][1])%mod;
}
int main()
{
    cin.sync_with_stdio(0);cin.tie(0);
	cin.exceptions(cin.failbit);
    int tc=1;
    //cin>>tc;
    prec();
    re(i,tc)
    	run();
    return 0; 
}
