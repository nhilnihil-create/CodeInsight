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

int k, n;
ll px[55];
ll py[55];

ll mycal(vl& cand) {
	sort(all(cand));
	ll ret = 1e18;
	for(int i=0; i+k<=sz(cand); ++i) {
		ret = min(ret, cand[i+k-1] - cand[i]);
	}
	return ret;
}

ll solve(int k) {
	vi order(n);
	rep(i,0,n) {
		order[i] = i;
	}
	sort(all(order), [&](int i, int j) {
		return px[i] < px[j];
	});
	ll ret = 4e18;
	for(int i=0; i+k<=n; ++i) {
		int idx = order[i];
		int jdx = order[i+k-1];
		ll w = px[jdx] - px[idx];
		vl cand;
		rep(j,i,i+k) {
			cand.pb(py[order[j]]);
		}
		ll h = mycal(cand);
		ret = min(ret, h * w);
	}
	sort(all(order), [&](int i, int j) {
		return py[i] < py[j];
	});
	for(int i=0; i+k<=n; ++i) {
		int idx = order[i];
		int jdx = order[i+k-1];
		ll h = py[jdx] - py[idx];
		vl cand;
		rep(j,i,i+k) {
			cand.pb(px[order[j]]);
		}
		ll w = mycal(cand);
		ret = min(ret, h * w);
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	cin >> n >> k;
	rep(i,0,n) {
		cin >> px[i] >> py[i];
	}
	ll ret = solve(k);
	rep(i,k+1,n+1) {
		ret = min(ret, solve(i));
	}
	cout << ret << '\n';
	return 0;
}
