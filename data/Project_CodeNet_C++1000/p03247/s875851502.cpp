/*input
3
-1 0
0 3
2 -1
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
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
	out<<'('<<P.F<<','<<P.S<<')';
	return out;
}

//}}}
const ll maxn=1005;
const ll maxlg=__lg(maxn)+2;
const ll INF64=80000000000000000LL;
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

vector<ll> v;
ll x[maxn],y[maxn];

string ans[maxn];

int main()
{
	IOS;
	int n;
	cin>>n;
	REP(i,n) cin>>x[i]>>y[i];

	ll cur=1;
	while(SZ(v)<35) v.pb(cur),cur<<=1;

	REP(i,n) if((x[0]%2+y[0]%2+10)%2!=(x[i]%2+y[i]%2+10)%2){
		cout<<"-1\n";
		return 0;
	}

	if((x[0]+y[0])%2){
		cout<<SZ(v)<<'\n';
		REP(i,SZ(v)) cout<<v[i]<<" \n"[i==SZ(v)-1];
	}
	else{
		cout<<SZ(v)+1<<'\n';
		cout<<1<<' ';
		REP(i,SZ(v)) cout<<v[i]<<" \n"[i==SZ(v)-1];
	}

	if((x[0]+y[0])%2==0){
		REP(i,n) ans[i].pb('R'),x[i]--;
	}

	REP(i,n){
		REP(j,SZ(v)-1){
			if(x[i]%2){
				if((x[i]+y[i]-1)/2%2){
					ans[i].pb('R');
					x[i]--;
				}
				else ans[i].pb('L'),x[i]++;
			}
			else{
				if((x[i]+y[i]-1)/2%2){
					y[i]--;
					ans[i].pb('U');
				}
				else ans[i].pb('D'),y[i]++;
			}
			x[i]>>=1;
			y[i]>>=1;
		}
		if(x[i]==1) ans[i].pb('R');
		else if(x[i]==-1) ans[i].pb('L');
		else if(y[i]==1) ans[i].pb('U');
		else ans[i].pb('D');
	}
	REP(i,n) cout<<ans[i]<<'\n';

	return 0;
}
