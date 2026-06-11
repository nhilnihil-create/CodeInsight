#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define ld long double
#define FAST ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define ins insert
#define ph push
#define mmst(x,v) memset(x,v,sizeof(x))
#define all(x) (x).begin(), (x).end()
#define LLINF ((long long)1e18)
#define MAXN 300006
#define FOR(i,s,e) for(ll i=s;i<e;i++)
typedef pair <ll, ll> pi;
typedef pair <ll, pi> spi;
ll n,arr[MAXN],sum[MAXN],ans=LLINF;
ll A,B,C,D,L,R;
void getans() {
	ans=min(ans,max({A,B,C,D})-min({A,B,C,D}));
}

int main()
{
	FAST
	cin>>n;
	for(ll i=1;i<=n;++i)cin>>arr[i];
	for(ll i=1;i<=n;++i)sum[i]=sum[i-1]+arr[i];
	ll opt_pos = 0, diff = LLINF; A=arr[1],B=arr[2];
	for(ll i=3;i<=n;++i) {
		if(diff > llabs((sum[n]-sum[i])-(sum[i]-sum[2]))) diff = llabs((sum[n]-sum[i])-(sum[i]-sum[2])), opt_pos = i;
	}
	C=sum[opt_pos]-sum[2];
	D=sum[n]-sum[opt_pos];
	getans();
	L=1,R=opt_pos;
	for(ll mid = 3; mid <= n-2; mid ++) {
		B+=arr[mid]; C-=arr[mid];
		while(L+1 < mid) {
			if(llabs(A-B) >= llabs(sum[L+1]-(sum[mid]-sum[L+1]))) {
				++L; A += arr[L]; B -= arr[L];
			}
			else break;
		}
		while(R+1 < n) {
			if(llabs(C-D) >= llabs((sum[R+1]-sum[mid])-(sum[n]-sum[R+1]))) {
				++R; C += arr[R]; D -= arr[R];
			}
			else break;
		}
		getans();
	}
	cout<<ans<<'\n';
	return 0;
}