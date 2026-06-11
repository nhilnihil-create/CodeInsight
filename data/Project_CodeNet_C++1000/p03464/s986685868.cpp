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

int k;
vl a;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	cin >> k;
	a.resize(k);
	rep(i,0,k) {
		cin >> a[i];
	}
	reverse(all(a));
	if(a[0] != 2) {
		cout << -1 << endl;
		return 0;
	}
	ll l = 2;
	ll r = 3;
	rep(i,1,k) {
		if(a[i] == a[i-1]) {
			continue;
		}

		ll nr = (r/a[i]) * a[i];
		if(nr < l) {
			cout << -1 << endl;
			return 0;
		}
		ll nl = (l/a[i]) * a[i];
		if(nl < l) nl += a[i];
		nr = nr + a[i] - 1;
		l = nl;
		r = nr;
	}
	cout << l << ' ' << r << endl;
	return 0;
}
