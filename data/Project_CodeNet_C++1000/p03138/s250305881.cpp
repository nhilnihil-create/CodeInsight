#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif




ll n, k;

// vx[i] : ビットiをxにした時のfの値
ll v0[50];
ll v1[50];


int main(){
	cin >> n >> k;
	
	vector<ll> a(n);
	rep(i,n)
		cin >> a[i];
	
	rep(i,n){
		rep(j,50){
			ll b = 1LL << j;
			if ( a[i] & b )
				v0[j] += b;
			else
				v1[j] += b;
		}
	}
	
	rep(i,50)
		eprintf( "%d: %lld %lld\n", i, v0[i], v1[i] );
	
	vector<ll> dp0(51); // dp0[i] xがi桁以下でf(x)の最大値
	vector<ll> dp1(51); // dp1[i] xがi桁以下 かつx<=(kの下i桁) でf(x)の最大値
	rep(i,50){
		dp0[i+1] = max(v0[i],v1[i]) + dp0[i];
		dp1[i+1] = (k & (1LL<<i))
			? max({
				dp0[i]+v0[i],
				dp1[i]+v0[i],
				dp1[i]+v1[i],
			}) 
			: dp1[i] + v0[i];
	}
	
	cout << dp1[50] << endl;
	
	return 0;
}


