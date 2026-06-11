#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPD(i,n) for(int i=(n)-1;i>=0;--i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
const ll MOD = 1E9+7;
const int INF = 1E9;
const double EPS = 1E-9;
const double PI = atan(1.0) * 4.0;
template<class T> T getbit(T s, int i) {return s>>i&1;}
template<class T> void flipbit(T& s, int i) {s^=(1LL<<i);}
constexpr int cntbit(ll x) {return __builtin_popcountll(x);}
constexpr int lg2(ll x) {return __lg(x);} // return int(log2(x))
// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
ll fpow(ll a,ll p){ll res=1LL;while(p){if(p&1LL) res=res*a%MOD;a=a*a%MOD;p>>=1LL;} return res;}

const int N=2005;
int n,k,q,res,a[N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k>>q;
	REP(i,n) cin>>a[i];
	a[n]=-INF;
	res=INF;
	REP(i,n){
		int last=0;
		vector<int> v;
		REP(j,n+1)
			if(a[i]>a[j]){
				if(j-last>=k){
					vector<int> tmp;
					FOR(t,last,j-1) tmp.pb(a[t]);
					sort(all(tmp));
					REP(t,sz(tmp)-k+1) v.pb(tmp[t]);
				}
				last=j+1;
			}
		sort(all(v));
		if(sz(v)>=q) res=min(res,v[q-1]-v[0]);
	}
	cout<<res<<'\n';
}

