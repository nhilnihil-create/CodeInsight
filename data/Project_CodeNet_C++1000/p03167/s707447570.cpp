/*
auth - @sportykush
*/

#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; 
// using namespace __gnu_pbds;

typedef long long int ll;
typedef long double ld;

//#define mp make_pair
#define bug(v)                    cerr<<#v<<" = "<<(v)<<endl;
#define bug2(v1,v2)               cerr<<#v1<<" = "<<(v1)<< ' ' << #v2<<" = "<<(v2)<<endl;
#define ERASE(x)                  x.erase(unique(x.begin(),x.end()),x.end())
#define pb                        emplace_back
#define vii                       vector<int>
#define vll                       vector<ll>
#define vpll                      vector< pair <ll,ll> >
#define pll                       pair <ll,ll>
#define pii                       pair <int,int>
#define pq                        priority_queue< int >
#define khtm                      "\n"
#define F                         first
#define S                         second
#define fr(i,a,n)                 for(i=a;i<n;i++)
#define mem(arr,l)                memset(arr,l,sizeof arr)
#define ALL(x)                    x.begin(), x.end()
#define frr(i,a,n)                for(i=n-1;i>=a;i--)
#define fast                      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define testcase                  ll T; cin>>T; while(T--)


const double pi = 3.14159265359;
const int MAX = 1e6 +2;
const ll inf =  1e18;
const int N = 1010;
const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
//const ll mod = 998244353;
const ll mod = 1000000007;
inline ll add(ll a,ll b){a+=b;if(a>=mod)a-=mod;return a;}
inline ll mul(ll a,ll b){return (((a+mod)%mod)*(b+mod)%mod)%mod;}
inline ll power(ll a,ll b){ll rt=1;while(b>0){if(b&1)rt=mul(rt,a);a=mul(a,a);b>>=1;}return rt;}
inline ll modInverse(ll n, ll p){ return power(n, p-2)%p; }

/*
important builtin functions
__gcd(value1, value2)
__builtin_ffs(x)
  Number of leading zeroes: __builtin_clz(x)
  Number of trailing zeroes : __builtin_ctz(x)
  Number of set bits: __builtin_popcount(x)
*/
 
void stArt()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}
void eNd()
{
	#ifndef ONLINE_JUDGE
  	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s";
  	#endif
}

//////////////////// start /////////////////////////////////
 

ll i,j,k,l,m,r,n;
//ll a[MAX],b[MAX];


int main()
{
 
stArt();
fast
//cout << setprecision(15) << fixed;

cin >> n >> m;
//m = n;
char a[n+1][m+1];
ll dp[n+1][m+1];
fr(i,0,n)
	fr(j,0,m){
		cin >> a[i][j];
		//dp[i][j] = 1;
	}
	mem(dp,0);
fr(i,0,n)
	if(a[i][0] == '#')
		break;
	else
		dp[i][0] = 1;
fr(i,0,m)
	if(a[0][i] == '#')
		break;
	else
		dp[0][i] = 1;
// mem(dp,1);
// dp[0][0] = 1;

fr(i,1,n)
{
	fr(j,1,m)
	{
		if(a[i][j] == '#')
			dp[i][j] = 0;
		else
		{
			//if(i)
				dp[i][j] = add(dp[i][j-1],dp[i-1][j]);
			// if(j)
			// 	dp[i][j] = add(dp[i][j],dp[i][j-1]);
		}
	}
}
// fr(i,0,n){
// 	fr(j,0,m)
	
// 		cout << dp[i][j] << ' ';
// 		cout << "\n";
// 	}
cout << dp[n-1][m-1];


 eNd();
  return 0;
 
}