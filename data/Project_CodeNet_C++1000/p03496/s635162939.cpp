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

int n;
vl a;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	cin >> n;
	a.resize(n);
	bool isValid = true;
	rep(i,0,n) {
		cin >> a[i];
		if(i>0 && a[i-1] > a[i]) {
			isValid = false;
		}
	}
	if(isValid) {
		cout << 0 << '\n';
		return 0;
	}
	int idx = 0;
	rep(i,0,n) {
		if(abs(a[idx]) < abs(a[i])) {
			idx = i;
		}
	}
	vector<pair<int, int> > ret;
	rep(i,0,n) {
		a[i] += a[idx];
		ret.pb(mp(idx,i));
	}
	bool flag = (a[idx] > 0);
	if(flag) {
		rep(i,0,n-1) {
			if(a[i] > a[i+1]) {
				a[i+1] += a[i];
				ret.pb(mp(i,i+1));
			}
		}
	} else {
		per(i,0,n-1) {
			if(a[i] > a[i+1]) {
				a[i] += a[i+1];
				ret.pb(mp(i+1,i));
			}
		}
	}
	cout << sz(ret) << '\n';
	rep(i,0,sz(ret)) {
		cout << ret[i].F+1 << ' ' << ret[i].S+1 << '\n';
	}
	return 0;
}
