#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb emplace_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 200110
ll MOD = 1e9+7;

vi des;
ll A[MAXN];
ll B[MAXN];
ll N,a;
ll S[MAXN];
ll fw[MAXN];

void update(ll x, ll v) {
	++x;
    for (; x<=2*N+1; x+=x&(-x)) fw[x] += v; 
}

ll query(ll x) {
    ll res = 0;
    for(; x; x-=x&(-x)) res += fw[x];
    return res;
}

ll sum(ll x, ll y){
	++x;++y;
	return query(y) - query(x-1);
}

ll ask(ll x){
	for (ll i=1;i<=N;++i){
		if (B[i]>=x)S[i]=1;
		else S[i]=-1;
	}
	for (ll i=1;i<=N;++i){S[i]+=S[i-1];}
	for (ll i=1;i<=N;++i){update(S[i], 1);}
	ll ans = 0;
	for (ll i=1;i<=N;++i){
		ll t = sum(S[i-1], 2*N);
		// cout<<"Query "<<S[i-1]<<' '<<t<<'\n';
		update(S[i], -1);
		ans+=t;
	}
	return ans;
}

int main(){
	cin>>N;
	S[0]=N;
	for (ll i=1;i<=N;++i){
		cin>>A[i];
		des.pb(A[i]);
	}
	sort(ALL(des));
	des.resize(unique(ALL(des)) - des.begin());
	for (ll i=1;i<=N;++i)B[i] = lb(ALL(des), A[i]) - des.begin();
	ll T = N*(N+1)/2;

	// for (ll i=0;i<=SZ(des);++i){
	// 	cout<<"Ask "<<i<<'\n';
	// 	cout<<ask(i)<<'\n';
	// }
	// return 0;
	ll lower = 0;
	ll upper = SZ(des);
	while (upper - lower > 1){
		ll mid=(upper+lower)/2;
		ll t = ask(mid);
		if (t*2>=T)lower=mid;
		else upper=mid;
	}
	if (ask(upper) *2 >= T)lower = upper;
	cout<<des[lower]<<'\n';
	// cout<<lower<<' '<<upper<<'\n';
}