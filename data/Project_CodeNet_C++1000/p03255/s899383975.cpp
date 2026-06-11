#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define FORR(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)

#define ALL(v) (v).begin(), (v).end()
#define CHMIN(a,b) (a)=min((a),(b))
#define CHMAX(a,b) (a)=max((a),(b))

#define DEBUG(x) cerr<<#x<<": "<<(x)<<endl;
#define DEBUG_VEC(v) cerr<<#v<<": ";for(auto x:v)cerr<<x<<" ";cerr<<endl

#define MOD 1000000007

int n;
ll xx;
ll x[252521];
ll sm[252521];

int main(){
	scanf("%d%lld",&n,&xx);
	REP(i,n)scanf("%lld",x+i);
	REP(i,n)sm[i+1] = sm[i] + x[i];
	ll ans = 1ll<<62;
	FOR(y,1,n+1){
		ll tmp = 5ll*sm[n] + (ll)xx*n;
		tmp += (ll)y*xx;
		int rgt = n-y;
		ll coe = 0;
		while(rgt>0){
			int nxt = max(rgt-y,0);
			__int128 add = 1;
			add *= coe;
			add *= sm[rgt]-sm[nxt];
			add += tmp;
			if(add > ans){
				tmp = ans;
				break;
			}
			tmp = add;
			rgt = nxt;
			coe += 2;
		}
		CHMIN(ans, tmp);
	}
	printf("%lld\n",ans);
	return 0;
}
