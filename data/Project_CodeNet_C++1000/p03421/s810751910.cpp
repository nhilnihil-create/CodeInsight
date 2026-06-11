#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll N=3e5+5;
const ll MOD=1e9+7;
const ld pi=3.14159265359;
const ll INF=(1LL<<60);
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define setp setprecision
#define lwb lower_bound
#define SZ(a) (ll)a.size()

ll n,a,b,ans[N],id,le,l;
vector<ll> v;

int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>a>>b;
	if(n<a+b-1||n>a*b){cout<<-1;return 0;}
	for(ll i=1;i<=b;i++)ans[i]=b+1-i;
	le=n-b;id=b+1;
	REP(j,a-1){if(j<le%(a-1))v.pb(le/(a-1)+1);else v.pb(le/(a-1));}
	l=b+1;id=b;
	for(auto j:v){
		id+=j;
		for(ll i=l;i<l+j;i++){
			ans[i]=id--;
		}
		id+=j;l=l+j;
	}
	REP1(i,n)cout<<ans[i]<<" ";
	return 0;
}
