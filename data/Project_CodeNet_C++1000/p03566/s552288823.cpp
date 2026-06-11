#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef complex<double> Point;

#define PI acos(-1.0)
#define EPS 1e-10
const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,N) for(int i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define fi first
#define se second
#define N_SIZE (1LL << 20)
#define NIL -1

ll sq(ll num) { return num*num; }
ll mod_pow(ll x, ll n) {
	if (n == 0)return 1;
	if (n == 1)return x%MOD;
	ll res = sq(mod_pow(x, n / 2));
	res %= MOD;
	if (n % 2 == 1) {
		res *= x;
		res %= MOD;
	}
	return res;
}

ll n;
double v[50000];
double rv[50000];

int main(){
	cin >> n;
	vector<P> vp(n);
	rep(i,n)cin >> vp[i].first;
	rep(i,n)cin >> vp[i].second;
	ll sum = 0;
	rep(i,n){
		ll t = vp[i].first * 2;
		ll vv = vp[i].second;
		for(ll i = sum+1;i <= sum+t;i++)v[i] = vv;
		for(ll i = sum;i < sum+t;i++)rv[i] = vv;
		sum += t;
	}
	for(ll i = 1;i <= sum;i++){
		v[i] = min(v[i-1]+0.5,v[i]);
	}
	for(ll i = sum-1;i >= 0;i--){
		rv[i] = min(rv[i+1]+0.5,rv[i]);
	}
	// for(ll i = sum;i >= 0;i--){
	// 	cout << (double)i*0.5 <<" "<< rv[i] << endl;
	// }
	double ans = 0;
	rep(i,sum){
		// cout << (double)i*0.5 <<" "<< min(rv[i],v[i]) << endl;
		double vv = min(rv[i],v[i]);
		double vv2 = min(rv[i+1],v[i+1]);
		ans += (min(vv,vv2)*0.5 + fabs(vv-vv2)*0.25);
	}
	printf("%.10lf\n",ans);
}