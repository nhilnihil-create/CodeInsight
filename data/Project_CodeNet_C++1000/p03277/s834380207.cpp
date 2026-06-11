/*input
10
5 9 5 9 8 9 3 5 4 3
*/
#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define F first
#define S second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define pb push_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#ifdef leowang
#define debug(...) do{\
	fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
	_DO(__VA_ARGS__);\
}while(0)
template<typename I> void _DO(I&&x){cerr<<x<<endl;}
template<typename I,typename...T> void _DO(I&&x,T&&...tail){cerr<<x<<", ";_DO(tail...);}
#else
#define debug(...)
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
	out<<'('<<P.F<<','<<P.S<<')';
	return out;
}

//}}}
const ll maxn=300005;
const ll maxlg=__lg(maxn)+2;
const ll INF64=8000000000000000000LL;
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
const double PI=acos(-1);
//const ll p=880301;
//const ll P=31;

ll mypow(ll a,ll b){
	ll res=1LL;
	while(b){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		
		b>>=1;
	}
	return res;
}
ll a[maxn];

vector<ll> v;
vector<ll> pre;
vector<ll> _;

ll BIT[maxn];
int low(int i){return i&-i;}
void add(int n,int d){
	for(int i=n;i<maxn;i+=low(i)) BIT[i]+=d;
}
ll query(int n){
	ll ret=0;
	for(int i=n;i>0;i-=low(i)) ret+=BIT[i];
	return ret;
}

ll check(){ //return # of contiguous interval that its sum \ge 0
	pre.clear();
	pre.pb(0);
	for(ll i:v) pre.pb(pre.back()+i);
	_.clear();
	for(ll i:pre) _.pb(i);
	SORT_UNIQUE(_);
	REP(i,SZ(pre)) pre[i]=1+GET_POS(_,pre[i]);

	ll ret=0;
	REP(i,SZ(pre)){
		ret+=query(pre[i]);
		add(pre[i],1);
	}
	REP(i,SZ(pre)) add(pre[i],-1);
	return ret;
}


int main()
{
	IOS;
	ll n;
	cin>>n;
	REP(i,n) cin>>a[i];

	ll l=0,r=2e9;

	while(l!=r-1){
		ll mid=(l+r)/2;

		v.clear();
		REP(i,n){
			if(a[i]>=mid) v.pb(1);
			else v.pb(-1);
		}
		ll cnt=check();

		if(cnt>=n*(n+1)/2-cnt) l=mid;
		else r=mid;
	}
	cout<<l<<'\n';

	return 0;
}
