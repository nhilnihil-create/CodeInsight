#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int lu;
typedef vector< int > vi;
typedef vector < ll > vl;
typedef set <ll> sl;
typedef vector< vi > vvi;
typedef vector< vl > vvl;
typedef pair< int,int > ii;
typedef pair< ll,ll > il;
#define sz(a) ll((a).size())
#define test(t) ll t;cin>>t;while(t--)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define Vi vector
#define pr pair
#define mpr make_pair
#define fi first
#define se second
#define isnum(a) (a>=48 && a<=57)
#define isS(a) (a>='a' && a<='z')
#define isU(a) (a>='A' && a<='Z')
#define toS(a) (isU(a)?a+32:a)
#define toU(a) (isS(a)?a-32:a)
#define toC(a) a&15

set <ll> s[100005];
ll d[100005];

vector<char> prime (100000+1, true);
void sieve(ll n)
{	
	//O(nloglogn) time
	prime[0] = prime[1] = false;
	for (ll i=2; i<=n; ++i)
	{
		if (prime[i])
		{
			s[i].insert(i);			
			for (ll j=2*i; j<=n; j+=i)
			{
				prime[j] = false;
				s[j].insert(i);
			}
		}
	}
}
#define forn(i,e) for(int i = 0; i < e; i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define REP(i,a,b) for(i=a;i<=b;i++)
#define reprev(i,a,b) for(i=a;i>=b;i--)

#define leadzero(a) __builtin_clz(a) //count leading zeros
#define trailzero(a) __builtin_ctz(a) //count trailing zeros
#define bitcount(a) __builtin_popcount(a) // count set bits (add ll)
#define ln cout<<"\n"
#define sp cout<<" "
#define maxe(a) *max_element(a.begin(),a.end())
#define maxi(a) max_element(a.begin(),a.end())-a.begin()
#define mine(a) *min_element(a.begin(),a.end())
#define mini(a) min_element(a.begin(),a.end())-a.begin()
ll gcd(ll a, ll b) { if(b == 0) return a; return gcd(b, a % b); }
ll fastpowMOD(ll a, ll p,ll MOD){ if(p==0) return 1; ll z = fastpowMOD(a,p/2,MOD); z = (z*z)%MOD; if(p%2) z = (z*a)%MOD; return z; }
ll fastpow(ll a, ll p){ if(p==0) return 1; ll z = fastpow(a,p/2); z = (z*z); if(p%2) z = (z*a); return z; }

ll search1(ll a[], ll f,ll n)
{
	ll left=1;
	ll right=n+1;
	while(right-left>1)
	{
		ll mid = left + (right-left)/2;
		if(a[mid]<f)
		{
			left=mid;
		}
		else right=mid;
	}
	return a[left];
}

bool sortby(const pair<pair<ll,ll>,ll>& a,const pair<pair<ll,ll>,ll>& b)
{
if(a.fi.fi+a.fi.se==b.fi.fi+b.fi.se)return a.fi.se<b.fi.se;
else return a.fi.fi+a.fi.se < b.fi.fi+b.fi.se;
}
const ll INF = 1e18; 
vector<pair<pair<ll,ll>,ll> > wsv;
ll dp[1001][20001];

int  main(){
	ll n,i,j;
	cin >> n;
	wsv.resize(n+1);
	wsv[0].fi.fi=0;
	wsv[0].fi.se=0;
	wsv[0].se=0;
	REP(i,1,n)
	{
		cin  >> wsv[i].fi.se >> wsv[i].fi.fi >> wsv[i].se;
	}
	memset(dp,0,sizeof(dp));
	sort(all(wsv),sortby);
	wsv[0].fi.fi=INF;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=wsv[i].fi.fi+wsv[i].fi.se;j++)
		{
			ll col = j;
			if(col>wsv[i-1].fi.fi+wsv[i-1].fi.se)col=wsv[i-1].fi.fi+wsv[i-1].fi.se;
			ll col2 = j-wsv[i].fi.se;
			if(col2>wsv[i-1].fi.fi+wsv[i-1].fi.se)col2=wsv[i-1].fi.fi+wsv[i-1].fi.se;
			if(col2<0)
			{
				dp[i][j]=dp[i-1][col];
				continue;
			}
			dp[i][j]=max(dp[i-1][col],dp[i-1][col2]+wsv[i].se);
		}
	}
	cout << dp[n][wsv[n].fi.fi+wsv[n].fi.se] << endl;
	return 0;
}