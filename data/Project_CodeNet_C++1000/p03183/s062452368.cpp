#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 340
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ld pai=acos(-1);
ll n,MX=1e4+1;
ll a[1009];
ll w[1009],s[1009],v[1009];
ll dp[1009][10009];
bool cmp(ll a,ll b){
	return w[a]+s[a]<w[b]+s[b];
}
ll bt(ll id,ll crnt){
	crnt=min(crnt,MX);
	if(id==n)return 0;
	ll &ret=dp[id][crnt];
	if(ret!=-1)return ret;
	ret=0;
	ret=max(ret,bt(id+1,crnt));
	if(s[a[id]]>=crnt)ret=max(ret,bt(id+1,crnt+w[a[id]])+v[a[id]]);
	return ret;
}
int main(){
	mem(dp,-1);
	cin>>n;
	for(ll i=0;i<n;i++){
		a[i]=i;
		cin>>w[i]>>s[i]>>v[i];
	}
	sort(a,a+n,cmp);
	cout<<bt(0,0)<<endl;
}
