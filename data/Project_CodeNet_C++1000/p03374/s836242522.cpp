#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef set<ll> sl;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second

ll n, c;

vl v, x, rv, rx;
vl pv;
vl prv;

ll solve(vl v, vl x, vl rv, vl rx) {
	vl pv(n+1);
	vl prv(n+1);
	rep(i,1,n+1) {
		pv[i] = pv[i-1] + v[i];
		prv[i] = prv[i-1] + rv[i];
	}
	rep(i,1,n+1) {
		prv[i] -= rx[i];
	}
	rep(i,1,n+1) {
		prv[i] = max(prv[i],prv[i-1]);
	}
	ll ret = 0;
	for(int i=0; i<=n; ++i) {
		ll A = max(pv[i] - x[i],0LL);
		int j = n-i;
		ll B = max(prv[j] - x[i],0LL);
		ret = max(ret, A+B);
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	cin >> n >> c;
	//c /= 1e8;
	v.resize(n+1);
	x.resize(n+1);
	rep(i,1,n+1) {
		cin >> x[i] >> v[i];
		//x[i] /= 1e8;
		//v[i] /= 1e8;
	}
	rv.resize(n+1);
	rx.resize(n+1);
	rep(i,1,n+1) {
		rx[i] = c - x[n+1-i];
		rv[i] = v[n+1-i];
	}
	ll ret = solve(v, x, rv, rx);
	ret = max(ret, solve(rv,rx,v,x));
	cout << ret << '\n';
	return 0;
}
