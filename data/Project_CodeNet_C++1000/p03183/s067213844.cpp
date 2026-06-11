#include<bits/stdc++.h>
using namespace std;

// -----------------<fast IO>------------------
#define CIN 			ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FLSH 			fflush(stdout)
#define fileIO(name) \
    freopen(name".in", "r", stdin); \
    freopen(name".out", "w", stdout);
#define PRECISION(x) 	cout << fixed << setprecision(x);
#define endl 			"\n"
#define ll              long long int
// -----------------<Hardware instructions>------------------
#define onecount        __builtin_popcount
#define bparity 		__builtin_parity(x)
#define leading0 		__builtin_clz(x)
#define leftmostb		__builtin_ctz(x)
// -----------------<Container manipulation / traversal macros>------------------
#define mp 				make_pair
#define pb	 			push_back
#define F    			first
#define S 				second
#define sz(x) 			((int)((x).size()))
#define all(x) 			(x).begin(),(x).end()
#define fr(i,n) 		for(int (i)=0;(i)<(n);(i)++)
#define forn(i,a,b) 	for(int (i)=(a);(i)<=(b);(i)++)
#define fill(l,a)		memset((l) , (a) , sizeof(l))
// -----------------<Some common useful functions>------------------
#define Max(a,b)		( (a) > (b) ? (a) : (b))
#define Min(a,b)        ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)   ( (n >> b) & 1)
#define INDEX(arr,i)  	( lower_bound(all(arr),i)-arr.begin())
#define in(b,a)         ( (b).find(a) != (b).end())
// -----------------<TypeDef Start>------------------
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> pair_ll;
typedef vector<ll> vi;
typedef vector< std::vector<ll> > matrix;
typedef map<ll,ll> mii;
typedef vector<pair_ll> vec_p;
// -----------------<Constants>------------------
const int MAXN = 1000005;
const int SQRTN = 1003;
const int LOGN = 22;
const double PI=acos(-1);

const int INF=1e9;

const int MOD = 1000000007;
const int FMOD = 998244353;
const double eps = 1e-9;
// -----------------<Modular Arithmetic>------------------
template<typename T> T gcd(T a, T b)
	{return(b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b)
	{return(a*(b/gcd(a,b)));}
template<typename T> T add(T a, T b, T c = MOD)
	{T res=a+b;return(res>=c?res-c:res);}
template<typename T> T mod_neg(T a, T b, T c = MOD)
	{T res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
template<typename T> T mul(T a, T b, T c = MOD)
	{ll res=(ll)a*b;return(res>=c?res%c:res);}
inline ll mulmod(ll a,ll b, ll m = MOD)
	{ll q = (ll)(((ld)a*(ld)b)/(ld)m);ll r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;}
template<typename T>T expo(T e, T n)
	{T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template<typename T>T power(T e, T n, T m = MOD)
	{T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;}
template<typename T>T extended_euclid(T a, T b, T &x, T &y)
	{T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n = MOD)
	{T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}
// ------------------nCr---------------------------
/*
ll modInverse(ll n, ll p){return power(n, p-2);}
ll nCr(ll n, ll r, ll p=MOD){if (r==0) return 1;ll fac[n+1];fac[0]=1;for(lli=1;i<=n;i++)fac[i]=fac[i-1]*i%p;
	return (fac[n]*modInverse(fac[r],p)%p*modInverse(fac[n-r], p)%p)%p;}
*/
//-----------------sieve--------------------------
/*
bool C[MAX];
// ll C[MAX]={0};
//vi V1;
void sieve(){
    ll i,j;
    for(i=2;i<MAX;i++){if(!C[i]){
        // V1.pb(i);
        for(j=2*i;j<MAX;j=j+i){C[j]=true;}}}}
*/
//---------------------D-S-U-------------------
/*
long long int parent[MAX];
long long int size[MAX];
void initialise()
{ //cout<<MAX<<" ";
    for(long  long int i=0;i<MAX;i++)
    {
        parent[i]=i;
        //cout<<i<<" ";
        size[i]=1;
    }
}
long long int  root(long long int x)
{
    while(x!=parent[x])
    {
        parent[x]=parent[parent[x]];
        x=parent[x];
    }
    return x;
}
void union1(long long int x,long long int y)
{
    if(size[x]>=size[y])
    {
        size[x]+=size[y];
        parent[y]=x;

    }
    else
    {
        size[y]+=size[x];
        parent[x]=y;
    }
}*/
// --------------------------------------------------</TEMPLATE>--------------------------------------------------
ll maxo=1e9+7;

bool cmp(const pair<ll,pair<ll,ll> > &a,const pair<ll,pair<ll,ll> > &b)
{
	return (a.second.first+a.second.second<b.second.first+b.second.second);
}


void solve()
{
	ll  idx=0,x=0, y=0, m=0, curr=0, num=0, n1=0, n2=0, n3=0, n4=0, i=0 , j=0,p=0;
	ll root=0, sum=0, diff=INF, q=0, choice=0, d=0, len=0, beg=0, end=0, pos=0, cnt=0;
	ll lo=0, hi=0, mid=0, ans=0;
	bool flag = false;
	string s1, s2, s3, str;
	char ch, ch1, ch2, ch3, *ptr;
	double dub=0;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	ll n;

	cin>>n;

	vector<pair<ll,pair<ll,ll> > > vec(n+1);

			for(i=1;i<=n;i++)
				cin>>vec[i].second.first>>vec[i].second.second>>vec[i].first;

			sort(vec.begin(),vec.end(),cmp);

			ll w[n+1],s[n+1],v[n+1];

			for(i=1;i<=n;i++)
				{
					w[i]=vec[i].second.first;
					s[i]=vec[i].second.second;
					v[i]=vec[i].first;

					//cout<<w[i]<<" "<<s[i]<<" "<<v[i]<<endl;
				}

				//cout<<endl;

			ll mino=-INF;

			for(i=1;i<=n;i++)
				mino=Max(mino,vec[i].second.second+vec[i].second.first);

			//cout<<mino<<endl;

			ll dp[n+1][mino+1];

			memset(dp,0,sizeof(dp));

			for(i=1;i<=n;i++)
				dp[i][0]=0;

			for(i=0;i<=mino;i++)
				dp[0][i]=0;

			dp[0][0]=0;

			//for(i=1;i<=n;i++)
			//	dp[i][0]=0;

			//cout<<mino<<endl;
			
			
				for(i=1;i<=n;i++)
					for(j=1;j<=mino;j++)
					{

						if(w[i]<=j && s[i]>=j-w[i])
							dp[i][j]=Max(dp[i-1][j-w[i]]+v[i],dp[i-1][j]);
						else if(w[i]>j) dp[i][j]=dp[i-1][j];
						else 
							dp[i][j]=Max(dp[i-1][j],dp[i-1][s[i]]+v[i]);

					}

				cout<<dp[n][mino]<<endl;

}


	



int main(){
	CIN;
	ll t;
	//cin>>t;
	//while(t--)
		solve();
	

	return 0;
}